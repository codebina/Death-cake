//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_ANIMAL_H
#define OOP_ANIMAL_H

#include <memory>
#include "itemAnimal.h"

class animal {
    std::string nume;
    std::string specie;
    int zileMaxProdus;
    int zilePanaProdus; // contorizează ciclul de producție


public:
    animal(const std::string &nume, const std::string &specie, int zileMaxProdus);

    void avansZi();

    std::unique_ptr<itemAnimal> colecteazaProdus();

    friend std::ostream &operator<<(std::ostream &os, const animal &anim);
};

#endif //OOP_ANIMAL_H
