//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <map>
#include <vector>
#include "planta.h"
#include "ferma.h"
#include "reteta.h"

class player {
    std::string nume;
    std::map<std::string,int> inventar;
    int energie;
    ferma ferma_cur;
    std::vector<reteta> retete;

public:
    player(const std::string &nume, const ferma &ferma_cur);

    void planteaza(const planta &planta);
    void add_inventar(const planta &planta, int cantitate);
    void add_reteta(const reteta &reteta);
    void uda_plante();
    void recolta();
    void cauta_reteta();
    void prepara(const reteta &reteta) const;
    void somnic();

    friend std::ostream &operator<<(std::ostream &os, const player &player);
};


#endif //OOP_PLAYER_H