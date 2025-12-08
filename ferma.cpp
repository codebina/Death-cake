//
// Created by sabin on 11/2/2025.
//

#include "ferma.h"

#include <iostream>

int ferma::zi_cur = 1;

int ferma::get_ziua_curenta() {
    return zi_cur;
}
ferma::ferma(const std::string &nume) : nume(nume) {}

bool ferma::is_empty() {
    return(plante.empty());
};

void ferma::add_planta(const planta &p) {
    plante.push_back(p);
    std::cout << "A fost plantata planta: " << p.get_nume()
              << ". Va creste in " << p.get_z_crestere() << " zile.\n";
}
void ferma::add_animal(const animal &a) {
    animale.push_back(a);
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
    for (auto &a : animale) {
        a.avans_zi();
    }
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
std::vector<std::unique_ptr<itemAnimal>> ferma::colecteaza_produse_animale() {
    std::vector<std::unique_ptr<itemAnimal>> produse;
    for (auto &a : animale) {
        if (auto produs = a.colecteaza_produs()) {
            produse.push_back(std::move(produs)); // Transfer de proprietate (unique_ptr)
        }
    }
    return produse;
}
std::vector<planta>& ferma::get_plante() { return plante; }

std::ostream &operator<<(std::ostream &os, const ferma &f) {
    os << "Ferma: " << f.nume << ", Zi curenta: " << f.zi_cur << "\n";
    os << "Plante:\n";
    for (const auto &p : f.plante)
        os << "  " << p << "\n";
    os << "Animale:\n"; // Nou
    if (f.animale.empty()) os << "  Niciun animal in ferma.\n";
    for (const auto &a : f.animale)
        os << "  " << a << "\n";

    return os;
}