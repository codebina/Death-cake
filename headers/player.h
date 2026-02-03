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
#include "animal.h"

class player {
    std::string nume;
    std::map<std::string, std::vector<std::unique_ptr<item> > > inventar;
    std::map<std::string, int> saculetSeminte;
    double energie;
    int bani;
    ferma fermaCur;
    std::vector<reteta> retete;

public:
    player(const std::string &nume, const ferma &fermaCur);

    void planteaza(const planta &planta);

    void adaugaAnimal(const animal &animal);

    void cumparaSeminte(const planta &planta, int cant);

    void addInventar(std::unique_ptr<item> it, int cantitate);

    void addReteta(const reteta &reteta);

    void udaPlante();

    void recolta();

    void colecteazaProduseAnimale();

    void pescuieste();

    void cautaReteta();

    void prepara(int indexReteta);

    void vindeItem(const std::string &numeItem, int cantitate);

    void somnic();

    void compara(const std::string& nume1, const std::string& nume2);

    [[nodiscard]] const std::vector<reteta>& getRetete() const { return retete; }

    friend std::ostream &operator<<(std::ostream &os, const player &player);
};


#endif //OOP_PLAYER_H
