//
// Created by sabin on 11/2/2025.
//

#include "../headers/player.h"
#include "../headers/reteta.h"
#include "../headers/satean.h"
#include "../headers/shop.h"
#include "../headers/exceptions.h"
#include "../headers/peste.h"
#include "../headers/itemFactory.h"
#include <iostream>
#include <map>

/**
 *
 * @brief Funcție șablon pentru a putea permite comparația între
 * iteme si rețete înainte să fie
 * preparate, pentru ca jucătorul să știe dacă merită să le prepare.
 */

template <typename T1, typename T2>
void executaComparatia(const T1& obj1, const T2& obj2) {
    std::cout << "\n--- COMPARATIE ---" << std::endl;
    std::cout << obj1.getNume() << ": " << obj1.calcPret() << " banuti" << std::endl;
    std::cout << obj2.getNume() << ": " << obj2.calcPret() << " banuti" << std::endl;

    if (obj1.calcPret() > obj2.calcPret())
        std::cout << "Verdict: " << obj1.getNume() << " este mai valoros.\n";
    else if (obj1.calcPret() < obj2.calcPret())
        std::cout << "Verdict: " << obj2.getNume() << " este mai valoros.\n";
    else
        std::cout << "Verdict: Valoare egala.\n";
}

player::player(const std::string &nume, const ferma &fermaCur)
    : nume(nume), energie(100), bani(300), fermaCur(fermaCur) {
}

void player::planteaza(const planta &planta) {
    if (saculetSeminte[planta.getNume()] <= 0) {
        throw MissingItemException("seminte de " + planta.getNume());
    }
    fermaCur.addPlanta(planta);
    saculetSeminte[planta.getNume()]--;
}

void player::adaugaAnimal(const animal &animal) {
    fermaCur.addAnimal(animal);
}

void player::cumparaSeminte(const planta &planta, int cant) {
    int total = shop::getInstance().calculeazaPret(planta.getNume(), cant);
    if (bani < total) {
        throw InsufficientFundsException("seminte de " + planta.getNume());
    }
    if (total == -1) return;
    saculetSeminte[planta.getNume()] += cant;
    bani -= total;
    std::cout << "Ai cumparat " << cant << " x " << planta.getNume()
            << " pentru " << total << " baniuti. Banuti ramasi: " << bani << "\n";
}

void player::addInventar(std::unique_ptr<item> it, int cantitate) {
    if (!it) return;
    std::string numeItem = it->getNume();

    inventar[numeItem].push_back(std::move(it));
    for (int i = 1; i < cantitate; ++i) {
        inventar[numeItem].push_back
                (std::unique_ptr<item>(inventar[numeItem].front()->clone()));
    }
}

void player::addReteta(const reteta &reteta) {
    retete.push_back(reteta);
}

void player::udaPlante() {
    int costPerPlanta = 5;
    int planteUdate = 0;

    if (fermaCur.isEmpty()) {
        std::cout << "Nu ai plantat nimic inca!\n";
        return;
    }

    for (auto &p: fermaCur.getPlante()) {
        if (!p.getUdata()) {
            if (energie >= costPerPlanta) {
                p.setUdata();
                energie -= costPerPlanta;
                planteUdate++;
            } else {
                throw InsufficientEnergyException("uda toate plantele");
            }
        }
    }

    if (planteUdate > 0)
        std::cout << "Au fost udate " << planteUdate << " plante.\n";
    else
        std::cout << "Toate plantele au fost deja udate azi sau nu ai energie.\n";
}

void player::recolta() {
    std::vector<planta> recoltaPlante = fermaCur.recoltare();

    if (recoltaPlante.empty()) {
        std::cout << "Nu s-a recoltat nicio planta (poate nu s-au copt inca).\n";
        return;
    }

    std::cout << "Incerci sa recoltezi:\n";

    for (const auto &p : recoltaPlante) {
        double efortNecesar = p.calculeazaEfort();
        if (this->energie >= efortNecesar) {
            this->energie -= static_cast<int>(efortNecesar);
            std::unique_ptr<item> itemInteligent(p.clone());
            addInventar(std::move(itemInteligent), 2);

            std::cout << "RECOLTAT " << p.getNume() << " x 2 (Efort depus: " << efortNecesar << ")\n";
        } else {
            // Daca ramane fara energie la jumatatea gradinii
            std::cout << "ESEC. Esti prea obosit sa mai scoti " << p.getNume()
                      << " din pamant! Te-ai oprit aici.\n";
            break; // Se oprește recoltarea pt restul
        }
    }
}

void player::colecteazaProduseAnimale() {
    if (energie < 20) {
        throw InsufficientEnergyException("colecta produse animale");
    }
    auto produse = fermaCur.colecteazaProduseAnimale();
    if (produse.empty()) {
        std::cout << "Nu sunt produse animale gata de colectare astazi.\n";
        return;
    }
    int totalColectat = 0;

    for (auto &produs: produse) {
        addInventar(std::move(produs), 1);
        totalColectat++;
    }
    energie -= 10;
    std::cout << "S-au colectat " << totalColectat << " produse. Energie consumata: 20.\n";
}

void player::pescuieste() {
    constexpr int costBaza = 5; // Efortul de a pregati undita
    if (energie < costBaza) {
        throw InsufficientEnergyException("pescui");
    }

    std::cout << "\nAlege o locatie de pescuit:\n";
    std::cout << "1. Balta \n2. Rau \n";
    int alegere;
    std::cin >> alegere;

    std::string locatiePescuit = (alegere == 2) ? "Rau" : "Balta";
    std::string numePesteGasit = (alegere == 2) ? "Somon" : "Crap";
    int pretPesteGasit = (alegere == 2) ? 80 : 50;

    energie -= costBaza;
    std::cout << "Pescuitul a inceput... (Energie initiala consumata: " << costBaza << ")\n";

    peste PesteNou(numePesteGasit, pretPesteGasit, locatiePescuit);
    PesteNou.pescuieste(); // Aici se genereaza greutatea random prin <random>

    double efortCaptura = PesteNou.calculeazaEfort();

    if (energie < efortCaptura) {
        std::cout << "Pestele e prea mare (" << PesteNou.getGreutate() << " kg)! ";
        std::cout << "Nu ai avut forta sa-l scoti si a rupt firul...\n";
        return;
    }

    energie -= efortCaptura;

    auto ptrPeste = std::unique_ptr<item>(PesteNou.clone());
    addInventar(std::move(ptrPeste), 1);

    std::cout << "Succes! Ai depus un efort suplimentar de " << efortCaptura
              << " unitati pentru a scoate acest " << numePesteGasit << "!\n";
}

void player::cautaReteta() {
    reteta sarmalePost("Sarmale de Post", {{"Varza", 2}, {"Morcov", 1}});
    reteta coliva("Coliva Traditionala", {{"Grau", 3}, {"Nuca Sfintita", 1}});
    satean<reteta> s1("Tanti Lenuta", "Leustean", sarmalePost);

    std::unique_ptr<item> nucaPtr = itemFactory::createItem("planta", "Nuca Sfintita");
    planta nucaSfintita = *dynamic_cast<planta*>(nucaPtr.get());
    satean<planta> s2("Parintele Vasile", "Rosie", nucaSfintita);

    satean<reteta> s3("Mamaie Stelutza", "Morcov", coliva);
    std::cout << "\n--- Oamenii din sat ---" << "\n";
    std::cout << "1. " << s1 << " (Ofera: " << s1.getOfera().getNume() << ")\n";
    std::cout << "2. " << s2 << " (Ofera: " << s2.getOfera().getNume() << ")\n";
    std::cout << "3. " << s3 << " (Ofera: " << s3.getOfera().getNume() << ")\n";
    std::cout << "0. Inapoi la ferma\n";
    std::cout << "Alegere: ";

    int alegere;
    if (!(std::cin >> alegere)) {
        std::cin.clear();
        return;
    }

    switch (alegere) {
        case 1:
            if (s1.troc(inventar)) {
                addReteta(s1.getOfera());
            }
            break;
        case 2:
            if (s2.troc(inventar)) {
                std::unique_ptr<item> recompensa(s2.getOfera().clone());
                addInventar(std::move(recompensa), 1);
            }
            break;
        case 3:
            if (s3.troc(inventar)) {
                addReteta(s3.getOfera());
            }
            break;
        default:
            break;
    }
}

void player::prepara(int indexReteta) {
    if (indexReteta >= 0 && indexReteta < static_cast<int>(retete.size())) {
        reteta& r = retete[indexReteta];
        std::unique_ptr<item> produsGatit = r.prepara(inventar);

        if (produsGatit) {
            double efort = produsGatit->calculeazaEfort();
            if (this->energie >= efort) {
                this->energie -= static_cast<int>(efort);
                std::cout << "Ai gatit: " << r.getNume() << "!\n";
            } else {
                std::cout << "Ai terminat de gatit dar ai lesinat de oboseala langa aragaz!\n";
                this->energie = 0;
            }
            addInventar(std::move(produsGatit), 1);
        }
    } else {
        std::cout << "Index invalid!\n";
    }
}

void player::vindeItem(const std::string &numeItem, int cantitate) {
    auto it = inventar.find(numeItem);
    if (it == inventar.end() || it->second.size() < static_cast<std::size_t>(cantitate)) {
        throw MissingItemException("Nu ai " + std::to_string(cantitate) + " unitati de "
                                   + numeItem + " pentru a le vinde.");
    }

    int venitTotal = 0;

    for (int i = 0; i < cantitate; ++i) {
        const std::unique_ptr<item> &itemPtr = it->second.back();
        int pretUnitate = itemPtr->calcPret();
        venitTotal += pretUnitate;
        it->second.pop_back();
    }
    bani += venitTotal;

    if (it->second.empty()) {
        inventar.erase(it);
    }

    std::cout << "Ai vandut " << cantitate << " x " << numeItem
            << " pentru " << venitTotal << " banuti. Total: " << bani << "\n";
}

void player::somnic() {
    std::cout << "Te-ai bagat la somn, energia ti-a fost reincarcata la maxim.\n";
    energie = 100;
    fermaCur.avansZi();
    std::cout << "Ziua curenta: " << ferma::getZiuaCurenta() << "\n";
    for (auto &pair: inventar) {
        for (auto &ptr: pair.second) {
            ptr->avansZi();
        }
    }
}
void player::compara(const std::string& n1, const std::string& n2) {

    item* i1 = inventar.count(n1) ? inventar[n1].back().get() : nullptr;
    item* i2 = inventar.count(n2) ? inventar[n2].back().get() : nullptr;

    const reteta* r1 = nullptr;
    for(const auto& r : retete) if(r.getNume() == n1) r1 = &r;

    const reteta* r2 = nullptr;
    for(const auto& r : retete) if(r.getNume() == n2) r2 = &r;

    if (i1 && i2) executaComparatia(*i1, *i2);
    else if (i1 && r2) executaComparatia(*i1, *r2);
    else if (r1 && i2) executaComparatia(*r1, *i2);
    else if (r1 && r2) executaComparatia(*r1, *r2);
    else std::cout << "Eroare: Nu detii '" << n1 << "' sau '" << n2 << "'.\n";
}
std::ostream &operator<<(std::ostream &os, const player &pl) {
    os << "Player: " << pl.nume << ", Energie: " << pl.energie << " , Banuti: " << pl.bani << "\n";
    os << pl.fermaCur;
    os << "Inventar:\n";
    if (pl.inventar.empty()) {
        os << "  Inventar gol.\n";
    } else {
        for (const auto &[nume, listaIteme]: pl.inventar) {
            if (!listaIteme.empty()) {
                os << "  " << nume << " x " << listaIteme.size()
                        << " - ( " << *listaIteme.front() << ")\n";
            }
        }
    }
    os << "Saculet cu seminte:\n";
    for (const auto &[nume, cantitate]: pl.saculetSeminte)
        os << "  " << nume << " x " << cantitate << "\n";
    if (pl.retete.empty()) std::cout << "Nicio reteta cunoscuta.\n";
    else {
        std::cout << "Retete:\n";
        for (const auto &r: pl.retete) os << " " << r;
    }
    return os;
}
