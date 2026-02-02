//
// Created by sabin on 12/7/2025.
//

#include "../headers/animal.h"

animal::animal(const std::string &nume, const std::string &specie, int zileMaxProdus)
    : nume(nume), specie(specie), zileMaxProdus(zileMaxProdus), zilePanaProdus(zileMaxProdus) {
}

void animal::avansZi() {
    if (zilePanaProdus > 0) {
        zilePanaProdus--;
    }
}

std::unique_ptr<itemAnimal> animal::colecteazaProdus() {
    if (zilePanaProdus == 0) {
        std::string numeProdus;
        int pretProdus;

        if (specie == "Vaca") {
            numeProdus = "Lapte";
            pretProdus = 50;
        } else if (specie == "Gaina") {
            numeProdus = "Ou";
            pretProdus = 20;
        } else {
            numeProdus = "ProdusNecunoscut";
            pretProdus = 10;
        }

        auto produs = std::make_unique<itemAnimal>(numeProdus, specie, pretProdus);
        zilePanaProdus = zileMaxProdus;
        return produs;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const animal &anim) {
    os << "Animal: " << anim.nume << " (" << anim.specie << ") - Zile pana la produs: " << anim.zilePanaProdus;
    return os;
}
