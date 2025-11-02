//
// Created by sabin on 11/2/2025.
//

#include "ferma.h"

#include <iostream>

ferma::ferma(const std::string &nume) : nume(nume), zi_cur(1) {}

void ferma::add_planta(const planta &p) {
    plante.push_back(p);
    std::cout << "A fost plantata planta: " << p.get_nume()
              << ". Va creste in " << p.get_z_crestere() << " zile.\n";
}

void ferma::avans_zi() {
    zi_cur++;
    std::cout << "A inceput o noua zi. Ziua curenta: " << zi_cur << ".\n";
    bool crescut = false;
    for (auto &p : plante) {
        crescut = p.creste();
        p.reset_udata();
    }
    if (!crescut)
        std::cout << "Unele plante nu au fost udate ieri!\n";
}

std::vector<planta> ferma::recoltare() {
    std::vector<planta> recolta;
    for (int i = static_cast<int>(plante.size()) - 1; i >= 0; i--) {
        if (plante[i].gata()) {
            recolta.push_back(plante[i]);
            plante.erase(plante.begin() + i);
        }
    }
    return recolta;
}

std::vector<planta>& ferma::get_plante() { return plante; }

std::ostream &operator<<(std::ostream &os, const ferma &f) {
    os << "Ferma: " << f.nume << ", Zi curenta: " << f.zi_cur << "\n";
    os << "Plante:\n";
    for (const auto &p : f.plante)
        os << "  " << p << "\n";
    return os;
}