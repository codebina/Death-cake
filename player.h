//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <vector>
#include "planta.h"
#include "ferma.h"

class player {
    std::string nume;
    std::vector<planta> inventar;
    int energie;
    ferma ferma_cur;

public:
    player(const std::string &nume, const ferma &ferma_cur);

    void planteaza(const planta &planta);
    void add_inventar(const planta &planta);
    void uda_plante();
    void recolta();
    void somnic();

    friend std::ostream &operator<<(std::ostream &os, const player &player);
};


#endif //OOP_PLAYER_H