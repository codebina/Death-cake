//
// Created by sabin on 11/2/2025.
//

#include "player.h"
#include "reteta.h"
#include "satean.h"
#include "shop.h"
#include <iostream>
#include <map>

player::player(const std::string &nume, const ferma &ferma_cur)
        : nume(nume), energie(100), bani(300), ferma_cur(ferma_cur) {}

void player::planteaza(const planta &planta) {
    if (saculet_seminte[planta.get_nume()]<=0) {
        std::cout<<"Nu ai destle seminte de "<<planta.get_nume()<<
            "! Poti cumpara seminte de la magazin!\n";
        return;
    }
    ferma_cur.add_planta(planta);
    saculet_seminte[planta.get_nume()]--;
}

void player::cumpara_seminte(const planta &planta, int cant, shop &shop) {
    int total=shop.calculeaza_pret(planta.get_nume(), cant);
    if (bani<total) {
        std::cout<<"Nu ai destui banuti!\n";
        return;
    }
    if (total==-1) return;
    saculet_seminte[planta.get_nume()]+=cant;
    bani-=total;
    std::cout << "Ai cumparat " << cant << " x " << planta.get_nume()
    << " pentru " << total << " baniuti. Banuti ramasi: " << bani << "\n";
}

void player::add_inventar(const planta &planta, int cantitate) {
    inventar[planta.get_nume()]+=cantitate;
}

void player::add_reteta(const reteta &reteta) {
    retete.push_back(reteta);
}

void player::uda_plante() {
    int cost_per_planta = 40;
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
                std::cout << "Nu ai destula energie pentru a uda planta: " << p.get_nume()
                << ". Nivel energie: " << energie << "\n";
                break;
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
        add_inventar(p, 2);
        std::cout << p.get_nume() << "\n";
    }
}
void player::cauta_reteta() {
    reteta sarmale_post("Sarmale de post", {{"Varza", 2}, {"Morcov", 1}});
    reteta ciorba("Ciorba de perisoare", {{"Carne tocata", 1},{"Cartof",3}});

    satean s1("Tanti Lenuta", planta("Leustean", 3), sarmale_post );
    satean s2("Mamaie Eugenia", planta("Rosie", 3), sarmale_post);
    satean s3("Baba Mariana", planta("Varza", 2), ciorba);

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

void player::prepara(const reteta &reteta) const {
    for (const auto&r :retete) {
        if (r.get_nume()==reteta.get_nume()) {
            if (reteta.prepara(inventar)) return;
            std::cout<<reteta;
            return;
        }

    }
    std::cout<<"Nu stii sa prepari reteta de "<<reteta.get_nume()<<" inca!\n";
}

void player::somnic() {
    std::cout << "Te-ai bagat la somn, energia ti-a fost reincarcata la maxim.\n";
    energie = 100;
    ferma_cur.avans_zi();
}

std::ostream &operator<<(std::ostream &os, const player &pl) {
    os << "Player: " << pl.nume << ", Energie: " << pl.energie << " , Banuti: "<<pl.bani<<"\n";
    os << pl.ferma_cur;
    os << "Inventar:\n";
    for (const auto &[nume, cantitate] : pl.inventar)
        os << "  " << nume <<" x "<<cantitate<<"\n";
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