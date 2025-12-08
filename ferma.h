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
    static int zi_cur;

public:
    static int get_ziua_curenta();
    explicit ferma(const std::string &nume);
    bool is_empty();
    void add_planta(const planta &p);
    void add_animal(const animal &a);
    void avans_zi();
    std::vector<planta> recoltare();

    [[nodiscard]] std::vector<planta>& get_plante();
    std::vector<std::unique_ptr<itemAnimal>> colecteaza_produse_animale();

    friend std::ostream &operator<<(std::ostream &os, const ferma &ferma);
};


#endif //OOP_FERMA_H