//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "item.h"
#include "planta.h"
#include "ferma.h"
#include "reteta.h"
#include "shop.h"
#include "animal.h"

class player {
    std::string nume;
    std::map<std::string, std::vector<std::unique_ptr<item>>> inventar;
    std::map<std::string, int> saculet_seminte;
    int energie;
    int bani;
    ferma ferma_cur;
    std::vector<reteta> retete;

public:
    player(const std::string &nume, const ferma &ferma_cur);
    void planteaza(const planta &planta);
    void adauga_animal(const animal &animal);
    void cumpara_seminte(const planta &planta, int cant, shop &shop);
    void add_inventar(std::unique_ptr<item> it, int cantitate);
    void add_reteta(const reteta &reteta);
    void uda_plante();
    void recolta();
    void colecteaza_produse_animale();
    void pescuieste();
    void cauta_reteta();
    void prepara(const reteta &reteta);
    void vinde_item(const std::string& nume_item, int cantitate);
    void somnic();
    friend std::ostream &operator<<(std::ostream &os, const player &player);
};


#endif //OOP_PLAYER_H