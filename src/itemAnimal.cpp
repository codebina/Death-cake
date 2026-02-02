//
// Created by sabin on 12/7/2025.
//

#include "../headers/itemAnimal.h"
#include <utility>

itemAnimal::itemAnimal(const std::string &nume, const std::string &provineAnimal, int sellPrice)
    : item(sellPrice), nume(nume), provineAnimal(provineAnimal), prospetime(10) {
}

itemAnimal::itemAnimal(const itemAnimal &other)
    : item(other), nume(other.nume), provineAnimal(other.provineAnimal),
      prospetime(other.prospetime) {
}

itemAnimal &itemAnimal::operator=(itemAnimal other) {
    swap(*this, other);
    return *this;
}

void swap(itemAnimal &a1, itemAnimal &a2) noexcept {
    using std::swap;
    swap(a1.sellPrice, a2.sellPrice);
    swap(a1.nume, a2.nume);
    swap(a1.provineAnimal, a2.provineAnimal);
    swap(a1.prospetime, a2.prospetime);
}

item *itemAnimal::clone() const {
    return new itemAnimal(*this);
}

itemAnimal::~itemAnimal() = default;

void itemAnimal::avansZi() {
    if (prospetime > 0) prospetime--;
}

int itemAnimal::calcPret() const {
    int pret_final = sellPrice;
    pret_final = pret_final * prospetime / 5;
    return pret_final;
}

/**
 *
 * @brief E greu de muls o vacă, dar ușor de cules un ou.
 * Generează un efort de bază pentru restul.
 */
double itemAnimal::calculeazaEfort() const {
    if (this->nume == "Lapte") return 25.0;
    if (this->nume == "Ou") return 5.0;
    return 10.0;
}

void itemAnimal::afis(std::ostream &os) const {
    os << "ItemAnimal: " << nume
            << ", Provine de la: " << provineAnimal
            << ", Pret de vandut: " << sellPrice
            << ", Prospetime: " << prospetime;
}
