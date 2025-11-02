//
// Created by sabin on 11/2/2025.
//

#include "planta.h"

planta::planta(const std::string &nume, int z_crestere)
        : nume(nume), z_crestere(z_crestere), udata(false) {}

planta::planta(const planta &other)
        : nume(other.nume), z_crestere(other.z_crestere), udata(other.udata) {}

planta &planta::operator=(const planta &other) {
    if (this != &other) {
        nume = other.nume;
        z_crestere = other.z_crestere;
        udata = other.udata;
    }
    return *this;
}

planta::~planta() = default;

void planta::set_udata() { udata = true; }
void planta::reset_udata() { udata = false; }

bool planta::gata() { return z_crestere <= 0; }

bool planta::creste() {
    if (udata && z_crestere > 0) {
        z_crestere--;
        return true;
    }
    return false;
}

bool planta::get_udata() const { return udata; }
std::string planta::get_nume() const { return nume; }
int planta::get_z_crestere() const { return z_crestere; }

std::ostream &operator<<(std::ostream &os, const planta &pl) {
    os << pl.nume << ", Zile pana creste: "
       << (pl.z_crestere > 0 ? std::to_string(pl.z_crestere) : "Gata de recoltat")
       << ", Udata: " << (pl.udata ? "Da" : "Nu") << "\n";
    return os;
}