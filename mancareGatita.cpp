//
// Created by sabin on 12/8/2025.
//

#include "mancareGatita.h"

mancareGatita::mancareGatita(const std::string& nume, int sell_price)
    : item(sell_price), nume(nume) {}

const std::string& mancareGatita::get_nume() const {
    return nume;
}

void mancareGatita::afis(std::ostream &os) const {
    os << "Mancare Gatita: " << nume << " , Pret de vanzare: " << sell_price << "";
}

item* mancareGatita::clone() const {
    return new mancareGatita(*this);
}

int mancareGatita::calcPret() const {
    return sell_price;
}

void mancareGatita::avans_zi() {
}