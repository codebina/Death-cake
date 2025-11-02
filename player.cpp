//
// Created by sabin on 11/2/2025.
//

#include "player.h"
#include <iostream>

player::player(const std::string &nume, const ferma &ferma_cur)
        : nume(nume), energie(100), ferma_cur(ferma_cur) {}

void player::planteaza(const planta &planta) {
    ferma_cur.add_planta(planta);
}

void player::add_inventar(const planta &planta) {
    inventar.push_back(planta);
}

void player::uda_plante() {
    int cost_per_planta = 40;
    int plante_udate = 0;

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
    for (auto &p : recolta) {
        add_inventar(p);
        std::cout << p.get_nume() << "\n";
    }
}

void player::somnic() {
    std::cout << "Te-ai bagat la somn, energia ti-a fost reincarcata la maxim.\n";
    energie = 100;
    ferma_cur.avans_zi();
}

std::ostream &operator<<(std::ostream &os, const player &pl) {
    os << "Player: " << pl.nume << ", Energie: " << pl.energie << "\n";
    os << pl.ferma_cur;
    os << "Inventar:\n";
    for (const auto &p : pl.inventar)
        os << "  " << p.get_nume() << "\n";
    return os;
}