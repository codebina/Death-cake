//
// Created by sabin on 12/7/2025.
//

#include "animal.h"

animal::animal(const std::string &nume, const std::string &specie, int zile_max_produs)
    : nume(nume), specie(specie), zile_max_produs(zile_max_produs), zile_pana_produs(zile_max_produs) {}

void animal::avans_zi() {
    if (zile_pana_produs > 0) {
        zile_pana_produs--;
    }
}

std::unique_ptr<itemAnimal> animal::colecteaza_produs() {
    if (zile_pana_produs == 0) {
        std::string nume_produs;
        int pret_produs;

        if (specie == "Vaca") {
            nume_produs = "Lapte";
            pret_produs = 50;
        } else if (specie == "Gaina") {
            nume_produs = "Ou";
            pret_produs = 20;
        } else {
            nume_produs = "ProdusNecunoscut";
            pret_produs = 10;
        }

        auto produs = std::make_unique<itemAnimal>(nume_produs, specie, pret_produs);
        zile_pana_produs = zile_max_produs;
        return produs;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const animal &anim) {
    os << "Animal: " << anim.nume << " (" << anim.specie << ") - Zile pana la produs: " << anim.zile_pana_produs;
    return os;
}