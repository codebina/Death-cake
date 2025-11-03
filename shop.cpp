//
// Created by sabin on 11/3/2025.
//

#include "shop.h"
#include <iostream>

shop::shop(const std::string &nume) : nume(nume) {}

int shop::calculeaza_pret(const std::string &nume_prod, int cant) {
    auto i = stoc.find(nume_prod);
    if (i == stoc.end()) {
        std::cout << "Produsul " << nume_prod << " nu exista in shop.\n";
        return -1;
    }
    int total = stoc[nume_prod]* cant;
    std::cout << "Pret total pentru " << cant << " x seminte de " << nume_prod
              << " este: " << total << " banuti.\n";
    return total;
}

void shop::adaugare_stoc(const std::string &nume_prod, int pret) {
    stoc[nume_prod] = pret;
}

std::ostream &operator<<(std::ostream &os, const shop &shop) {
    os << "Magazin: " << shop.nume << "\n";
    for (const auto &[prod, pret] : shop.stoc)
        os << "  " << prod << " - " << pret << " banuti\n";
    return os;
}

