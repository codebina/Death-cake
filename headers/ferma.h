//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_FERMA_H
#define OOP_FERMA_H

#include <string>
#include <vector>
#include "planta.h"
#include "animal.h"

class ferma {
    std::string nume;
    std::vector<planta> plante;
    std::vector<animal> animale;
    static int ziCur;

public:
    static int getZiuaCurenta();

    explicit ferma(const std::string &nume);

    bool isEmpty();

    void addPlanta(const planta &p);

    void addAnimal(const animal &a);

    void avansZi();

    std::vector<planta> recoltare();

    [[nodiscard]] std::vector<planta> &getPlante();

    std::vector<std::unique_ptr<itemAnimal> > colecteazaProduseAnimale();

    friend std::ostream &operator<<(std::ostream &os, const ferma &ferma);
};


#endif //OOP_FERMA_H
