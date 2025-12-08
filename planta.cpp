//
// Created by sabin on 11/2/2025.
//

#include "planta.h"
#include <utility>

planta::planta(const std::string &nume, int z_crestere, int sell_price)
        : item(sell_price), nume(nume), z_crestere(z_crestere), udata(false), prospetime(10) {}

planta::planta(const planta &other)
        :item(other), nume(other.nume), z_crestere(other.z_crestere), udata(other.udata),
prospetime(other.prospetime){}

planta &planta::operator=(planta other) {
    swap(*this, other);
    return *this;
}
void swap(planta& pl1, planta& pl2)noexcept {
    using std::swap;
    swap(pl1.sell_price, pl2.sell_price);  // OK, protected
    swap(pl1.nume, pl2.nume);
    swap(pl1.z_crestere, pl2.z_crestere);
    swap(pl1.udata, pl2.udata);
    swap(pl1.prospetime, pl2.prospetime);
}
item* planta::clone() const {
    return new planta(*this);
}
planta::~planta() = default;

void planta::set_udata() { udata = true; }
void planta::reset_udata() { udata = false; }

bool planta::gata ()const { return z_crestere <= 0; }

bool planta::creste() {
    if (udata && z_crestere > 0) {
        z_crestere--;
        return true;
    }
    return false;
}

bool planta::get_udata() const { return udata; }
const std::string& planta::get_nume() const { return nume; }
int planta::get_z_crestere() const { return z_crestere; }
void planta::avans_zi() {
    if (prospetime > 0) prospetime--;
}
int planta::calcPret() const {
    int pret_final = sell_price;
    pret_final = pret_final * prospetime / 10;
    return pret_final;
}

void planta::afis(std::ostream& os) const {
    os  << "Planta: " << nume
        << ", Zile pana creste: " << z_crestere
        << ", Udata: " << (udata ? "Da," : "Nu,") << " Pret de vandut: "
        << sell_price
        << ", Prospetime: " << prospetime;
}