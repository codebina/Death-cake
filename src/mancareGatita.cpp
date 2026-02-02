//
// Created by sabin on 12/8/2025.
//

#include "../headers/mancareGatita.h"

mancareGatita::mancareGatita(const std::string &nume, int sellPrice)
    : item(sellPrice), nume(nume) {
}

const std::string &mancareGatita::getNume() const {
    return nume;
}

void mancareGatita::afis(std::ostream &os) const {
    os << "Mancare Gatita: " << nume << " , Pret de vanzare: " << sellPrice << "";
}

item *mancareGatita::clone() const {
    return new mancareGatita(*this);
}

int mancareGatita::calcPret() const {
    return sellPrice;
}

void mancareGatita::avansZi() {
}

/**
 *
 * @brief Corporatistu' nu se pricepe :)
 */
double mancareGatita::calculeazaEfort() const {
    double efortPreparare = 40.0;
    return efortPreparare;
}
