//
// Created by sabin on 11/3/2025.
//

#include "../headers/shop.h"
#include <iostream>

shop::shop(const std::string& nume) : nume(nume) {}

shop& shop::getInstance() {
    static shop instance("Magazin Seminte");
    return instance;
}

int shop::calculeazaPret(const std::string &numeProd, int cant) {
    auto i = stoc.find(numeProd);
    if (i == stoc.end()) {
        std::cout << "Produsul " << numeProd << " nu exista in shop.\n";
        return -1;
    }
    int total = stoc[numeProd] * cant;
    std::cout << "Pret total pentru " << cant << " x seminte de " << numeProd
            << " este: " << total << " banuti.\n";
    return total;
}

void shop::adaugareStoc(const std::string &numeProd, int pret) {
    stoc[numeProd] = pret;
}

std::ostream &operator<<(std::ostream &os, const shop &shop) {
    os << "\nMagazin: " << shop.nume << "\n";
    for (const auto &[prod, pret]: shop.stoc)
        os << "  " << prod << " - " << pret << " banuti\n";
    return os;
}
