//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_FERMA_H
#define OOP_FERMA_H

#include <string>
#include <vector>
#include "planta.h"

class ferma {
    std::string nume;
    std::vector<planta> plante;
    int zi_cur;

public:
    explicit ferma(const std::string &nume);
    bool is_empty();
    void add_planta(const planta &p);
    void avans_zi();
    std::vector<planta> recoltare();

    [[nodiscard]] std::vector<planta>& get_plante();

    friend std::ostream &operator<<(std::ostream &os, const ferma &ferma);
};


#endif //OOP_FERMA_H