//
// Created by sabin on 12/7/2025.
//

#include "../headers/peste.h"
#include <algorithm>
#include <cstdlib>
#include <random>

peste::peste(const std::string &nume, int sellPrice, const std::string &locatie)
    : item(sellPrice), nume(nume), greutate(0.0), locatie(locatie) {
}

peste::peste(const peste &other)
    : item(other), nume(other.nume), greutate(other.greutate),
      locatie(other.locatie) {
}

peste &peste::operator=(peste other) {
    swap(*this, other);
    return *this;
}

void swap(peste &p1, peste &p2) noexcept {
    using std::swap;
    swap(p1.sellPrice, p2.sellPrice);
    swap(p1.nume, p2.nume);
    swap(p1.greutate, p2.greutate);
    swap(p1.locatie, p2.locatie);
}

item *peste::clone() const { return new peste(*this); }

peste::~peste() = default;

void peste::avansZi() {
}

int peste::calcPret() const {
    double pret = sellPrice;
    pret *= greutate;
    return static_cast<int>(pret);
}

void peste::afis(std::ostream &os) const {
    os << "Peste: " << nume
            << ", Greutate: " << greutate << " kg, "
            << "Locatie: " << locatie;
}

/**
 * @brief Am implementat librăria <random> pentru o generare corectă a valorilor aleatorii.
 * Funcția generează o greutate de 0.5kg - 2.5kg random.
 */
void peste::pescuieste() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.5, 2.5);
    greutate = dist(gen);
}

/**
 *
 * @brief Efortul este greutatea la pătrat (peștii mari sunt exponențial mai greu de prins)
 */
double peste::calculeazaEfort() const {
    return greutate * greutate * 5.0;
}
