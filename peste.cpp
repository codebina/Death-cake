//
// Created by sabin on 12/7/2025.
//

#include "peste.h"
#include <algorithm>
#include <cstdlib>

peste::peste(const std::string &nume, int sell_price, const std::string &locatie)
    : item(sell_price), nume(nume), greutate(0.0), locatie(locatie) {}

peste::peste(const peste &other)
    : item(other), nume(other.nume), greutate(other.greutate),
locatie(other.locatie) {}

peste &peste::operator=(peste other) {
    swap(*this, other);
    return *this;
}

void swap(peste &p1, peste &p2) noexcept {
    using std::swap;
    swap(p1.sell_price, p2.sell_price);
    swap(p1.nume, p2.nume);
    swap(p1.greutate, p2.greutate);
    swap(p1.locatie, p2.locatie);
}
item* peste::clone() const { return new peste(*this); }
peste::~peste() = default;
void peste::avans_zi() {}
int peste::calcPret() const {
    double pret = sell_price;
    pret *= greutate;
    return static_cast<int>(pret);
}

void peste::afis(std::ostream &os) const {
    os << "Peste: " << nume
       << ", Greutate: " << greutate << " kg, "
    << "Locatie: " << locatie;
}

void peste::pescuieste() {
    greutate = (std::rand() % 200 + 50) / 100.0; // 0.5kg - 2.5kg random
}