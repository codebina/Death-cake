//
// Created by sabin on 11/2/2025.
//

#include "../headers/planta.h"
#include <utility>

planta::planta(const std::string &nume, int zCrestere, int sellPrice)
    : item(sellPrice), nume(nume), zCrestere(zCrestere), udata(false), prospetime(10) {
}

planta::planta(const planta &other)
    : item(other), nume(other.nume), zCrestere(other.zCrestere), udata(other.udata),
      prospetime(other.prospetime) {
}

planta &planta::operator=(planta other) {
    swap(*this, other);
    return *this;
}

void swap(planta &pl1, planta &pl2) noexcept {
    using std::swap;
    swap(pl1.sellPrice, pl2.sellPrice);
    swap(pl1.nume, pl2.nume);
    swap(pl1.zCrestere, pl2.zCrestere);
    swap(pl1.udata, pl2.udata);
    swap(pl1.prospetime, pl2.prospetime);
}

item *planta::clone() const {
    return new planta(*this);
}

planta::~planta() = default;

void planta::setUdata() { udata = true; }
void planta::resetUdata() { udata = false; }

bool planta::gata() const { return zCrestere <= 0; }

bool planta::creste() {
    if (udata && zCrestere > 0) {
        zCrestere--;
        return true;
    }
    return false;
}

bool planta::getUdata() const { return udata; }
const std::string &planta::getNume() const { return nume; }
int planta::getZCrestere() const { return zCrestere; }

void planta::avansZi() {
    if (prospetime > 0) prospetime--;
}

int planta::calcPret() const {
    int pret_final = sellPrice;
    pret_final = pret_final * prospetime / 10;
    return pret_final;
}

/**
 *@brief Un factor de bază (ex: 10) înmulțit cu 1.5 dacă n-a fost udată (e mai greu de scos din pământ uscat)
 *
 */
double planta::calculeazaEfort() const {
    return 10.0 * (udata ? 1.0 : 1.5);
}

void planta::afis(std::ostream &os) const {
    os << "Planta: " << nume
            << ", Zile pana creste: " << zCrestere
            << ", Udata: " << (udata ? "Da," : "Nu,") << " Pret de vandut: "
            << sellPrice
            << ", Prospetime: " << prospetime;
}
