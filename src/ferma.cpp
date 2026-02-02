//
// Created by sabin on 11/2/2025.
//

#include "../headers/ferma.h"

#include <iostream>

int ferma::ziCur = 1;

int ferma::getZiuaCurenta() {
    return ziCur;
}

ferma::ferma(const std::string &nume) : nume(nume) {
}

bool ferma::isEmpty() {
    return (plante.empty());
};

void ferma::addPlanta(const planta &p) {
    plante.push_back(p);
    std::cout << "A fost plantata planta: " << p.getNume()
            << ". Va creste in " << p.getZCrestere() << " zile.\n";
}

void ferma::addAnimal(const animal &a) {
    animale.push_back(a);
}

void ferma::avansZi() {
    ziCur++;
    std::cout << "A inceput o noua zi. Ziua curenta: " << ziCur << ".\n";
    bool crescut = false;
    for (auto &p: plante) {
        crescut = p.creste();
        p.resetUdata();
    }
    if (!crescut)
        std::cout << "Unele plante nu au fost udate ieri!\n";
    for (auto &a: animale) {
        a.avansZi();
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

std::vector<std::unique_ptr<itemAnimal> > ferma::colecteazaProduseAnimale() {
    std::vector<std::unique_ptr<itemAnimal> > produse;
    for (auto &a: animale) {
        if (auto produs = a.colecteazaProdus()) {
            produse.push_back(std::move(produs)); // Transfer de proprietate (unique_ptr)
        }
    }
    return produse;
}

std::vector<planta> &ferma::getPlante() { return plante; }

std::ostream &operator<<(std::ostream &os, const ferma &f) {
    os << "Ferma: " << f.nume << ", Zi curenta: " << f.ziCur << "\n";
    os << "Plante:\n";
    for (const auto &p: f.plante)
        os << "  " << p << "\n";
    os << "Animale:\n"; // Nou
    if (f.animale.empty()) os << "  Niciun animal in ferma.\n";
    for (const auto &a: f.animale)
        os << "  " << a << "\n";

    return os;
}
