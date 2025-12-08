//
// Created by sabin on 11/2/2025.
//

#include "player.h"
#include "reteta.h"
#include "satean.h"
#include "shop.h"
#include "exceptions.h"
#include "peste.h"
#include <iostream>
#include <map>

player::player(const std::string &nume, const ferma &ferma_cur)
        : nume(nume), energie(100), bani(300), ferma_cur(ferma_cur) {}

void player::planteaza(const planta &planta) {
    if (saculet_seminte[planta.get_nume()]<=0) {
        throw MissingItemException("seminte de " + planta.get_nume());
    }
    ferma_cur.add_planta(planta);
    saculet_seminte[planta.get_nume()]--;
}
void player::adauga_animal(const animal &animal) {
    ferma_cur.add_animal(animal);
}

void player::cumpara_seminte(const planta &planta, int cant, shop &shop) {
    int total=shop.calculeaza_pret(planta.get_nume(), cant);
    if (bani<total) {
        throw InsufficientFundsException("seminte de " + planta.get_nume());
    }
    if (total==-1) return;
    saculet_seminte[planta.get_nume()]+=cant;
    bani-=total;
    std::cout << "Ai cumparat " << cant << " x " << planta.get_nume()
    << " pentru " << total << " baniuti. Banuti ramasi: " << bani << "\n";
}

void player::add_inventar(std::unique_ptr<item> it, int cantitate) {
    if (!it) return;
    std::string nume_item = it->get_nume();

    inventar[nume_item].push_back(std::move(it));
    for (int i = 1; i < cantitate; ++i) {
        inventar[nume_item].push_back
        (std::unique_ptr<item>(inventar[nume_item].front()->clone()));
    }
}
void player::add_reteta(const reteta &reteta) {
    retete.push_back(reteta);
}

void player::uda_plante() {
    int cost_per_planta = 5;
    int plante_udate = 0;

    if (ferma_cur.is_empty()) {
        std::cout<<"Nu ai plantat nimic inca!\n";
        return;
    }

    for (auto &p : ferma_cur.get_plante()) {
        if (!p.get_udata()) {
            if (energie >= cost_per_planta) {
                p.set_udata();
                energie -= cost_per_planta;
                plante_udate++;
            } else {
                throw InsufficientEnergyException("uda toate plantele");
            }
        }
    }

    if (plante_udate > 0)
        std::cout << "Au fost udate " << plante_udate << " plante.\n";
    else
        std::cout << "Toate plantele au fost deja udate azi sau nu ai energie.\n";
}

void player::recolta() {
    std::vector<planta> recolta = ferma_cur.recoltare();
    if (recolta.empty()) {
        std::cout << "Nu s-a recoltat nicio planta.\n";
        return;
    }
    std::cout << "Au fost recoltate:\n";
    for (const auto &p : recolta) {
        item* item_ptr = p.clone();
        std::unique_ptr<item> item_inteligent(item_ptr);
        add_inventar(std::move(item_inteligent), 2);
        std::cout << p.get_nume() << " x 2\n";
    }
}
void player::colecteaza_produse_animale() {
    if (energie < 20) {
        throw InsufficientEnergyException("colecta produse animale");
    }
    auto produse = ferma_cur.colecteaza_produse_animale();
    if (produse.empty()) {
        std::cout << "Nu sunt produse animale gata de colectare astazi.\n";
        return;
    }
    int total_colectat = 0;

    for (auto& produs : produse) {
        add_inventar(std::move(produs), 1);
        total_colectat++;
    }
    energie -= 10;
    std::cout << "S-au colectat " << total_colectat << " produse. Energie consumata: 20.\n";
}
void player::pescuieste() {
    constexpr int cost_energie = 15;
    if (energie < cost_energie) {
        throw InsufficientEnergyException("pescui");
    }

    std::cout << "\nAlege o locatie de pescuit:\n";
    std::cout << "1. Balta \n";
    std::cout << "2. Rau \n";
    int alegere;
    std::cin >> alegere;

    std::string locatie_pescuit;
    std::string nume_peste_gasit;
    int pret_peste_gasit;

    switch (alegere) {
        case 1: locatie_pescuit = "Balta"; nume_peste_gasit = "Crap"; pret_peste_gasit = 50; break;
        case 2: locatie_pescuit = "Rau"; nume_peste_gasit = "Somon"; pret_peste_gasit = 80; break;
        default: locatie_pescuit = "Balta"; nume_peste_gasit = "Crap"; pret_peste_gasit = 50;
    }

    energie -= cost_energie;
    std::cout << "Pescuitul a inceput... (Energie consumata: " << cost_energie << ")\n";

    peste PesteNou(nume_peste_gasit, pret_peste_gasit,  locatie_pescuit);
    PesteNou.pescuieste();
    auto ptr_pest = static_cast<peste*>(PesteNou.clone());
    auto ptr_peste=std::unique_ptr<peste> (ptr_pest);
    add_inventar(std::move(ptr_peste), 1);

    if (const auto* peste_ptr = dynamic_cast<peste*>(inventar[nume_peste_gasit].back().get())) {
        std::cout << "Ai pescuit un " << peste_ptr->get_nume()
                  << " de " << peste_ptr->get_greutate() << " kg in "
                  << peste_ptr->get_locatie() << "!\n";
    }
}
void player::cauta_reteta() {
    reteta sarmale_post("Sarmale de post", {{"Varza", 2}, {"Morcov", 1}});
    reteta ciorba("Ciorba de perisoare", {{"Carne tocata", 1},{"Cartof",3}});

    satean s1("Tanti Lenuta", "Leustean", sarmale_post );
    satean s2("Mamaie Eugenia", "Rosie", sarmale_post);
    satean s3("Baba Mariana", "Varza", ciorba);

    std::vector<satean> sateni = {s1, s2, s3};

    for (const auto &baba : sateni) {
        std::cout << baba;
        if (baba.troc(inventar)) {
            add_reteta(baba.get_ofera());
            std::cout << "Ai primit o noua reteta!\n";
            return;
        }
    }
}

void player::prepara(const reteta &reteta) {
    for (const auto&r :retete) {
        if (r.get_nume()==reteta.get_nume()) {
            if (reteta.prepara(inventar)) return;
            std::cout<<reteta;
            return;
        }

    }
    std::cout<<"Nu stii sa prepari reteta de "<<reteta.get_nume()<<" inca!\n";
}
void player::vinde_item(const std::string& nume_item, int cantitate) {
    auto it = inventar.find(nume_item);
    if (it == inventar.end() || it->second.size() < static_cast<std::size_t>(cantitate)) {
        throw MissingItemException("Nu ai " + std::to_string(cantitate) + " unitati de "
            + nume_item + " pentru a le vinde.");
    }

    int venit_total = 0;

    for (int i = 0; i < cantitate; ++i) {
        const std::unique_ptr<item>& item_ptr = it->second.back();
        int pret_unitate = item_ptr->calcPret();
        venit_total += pret_unitate;
        it->second.pop_back();
    }
    bani += venit_total;

    if (it->second.empty()) {
        inventar.erase(it);
    }

    std::cout << "Ai vandut " << cantitate << " x " << nume_item
              << " pentru " << venit_total << " banuti. Total: " << bani << "\n";
}
void player::somnic() {
    std::cout << "Te-ai bagat la somn, energia ti-a fost reincarcata la maxim.\n";
    energie = 100;
    ferma_cur.avans_zi();
    std::cout << "Ziua curenta: " << ferma::get_ziua_curenta() << "\n";
    for (auto& pair : inventar) {
        for (auto& ptr : pair.second) {
            ptr->avans_zi();
        }
    }
}

std::ostream &operator<<(std::ostream &os, const player &pl) {
    os << "Player: " << pl.nume << ", Energie: " << pl.energie << " , Banuti: "<<pl.bani<<"\n";
    os << pl.ferma_cur;
    os << "Inventar:\n";
    if (pl.inventar.empty()) {
        os << "  Inventar gol.\n";
    } else {
        for (const auto &[nume, lista_iteme] : pl.inventar) {
            if (!lista_iteme.empty()) {
                os << "  " << nume << " x " << lista_iteme.size()
                   << " - ( " << *lista_iteme.front() << ")\n";
            }
        }
    }
    os << "Saculet cu seminte:\n";
    for (const auto &[nume, cantitate] : pl.saculet_seminte)
        os << "  " << nume <<" x "<<cantitate<<"\n";
    if (pl.retete.empty()) std::cout<<"Nicio reteta cunoscuta.\n";
    else {
        std::cout<<"Retete:\n";
        for (const auto&r : pl.retete) os<< " "<< r;
    }
    return os;
}