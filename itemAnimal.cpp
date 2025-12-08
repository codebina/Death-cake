//
// Created by sabin on 12/7/2025.
//

#include "itemAnimal.h"
#include <utility>

itemAnimal::itemAnimal(const std::string &nume, const std::string &provine_animal,int sell_price)
        : item(sell_price), nume(nume), provine_animal(provine_animal), prospetime(10) {}

itemAnimal::itemAnimal(const itemAnimal &other)
        : item(other), nume(other.nume), provine_animal(other.provine_animal),
prospetime(other.prospetime) {}

itemAnimal &itemAnimal::operator=(itemAnimal other) {
    swap(*this, other);
    return *this;
}

void swap(itemAnimal &a1, itemAnimal &a2) noexcept {
    using std::swap;
    swap(a1.sell_price, a2.sell_price);
    swap(a1.nume, a2.nume);
    swap(a1.provine_animal, a2.provine_animal);
    swap(a1.prospetime, a2.prospetime);
}

item* itemAnimal::clone() const {
    return new itemAnimal(*this);
}

itemAnimal::~itemAnimal() = default;
void itemAnimal::avans_zi() {
    if (prospetime > 0) prospetime--;
}
int itemAnimal::calcPret() const {
    int pret_final = sell_price;
    pret_final = pret_final * prospetime / 5;
    return pret_final;
}

void itemAnimal::afis(std::ostream &os) const {
    os  << "ItemAnimal: " << nume
        << ", Provine de la: " << provine_animal
        << ", Pret de vandut: " << sell_price
        << ", Prospetime: " << prospetime;
}
