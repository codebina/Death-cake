//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_SATEAN_H
#define OOP_SATEAN_H

#include "planta.h"
#include "reteta.h"

#include <map>
#include <string>
#include <iostream>


class satean {
    std::string nume;
    planta cere;
    reteta ofera;
    public:
    satean(const std::string &nume, const planta &cere, const reteta &ofera);
    [[nodiscard]] reteta get_ofera() const;
    bool troc(const std::map<std::string, int>&inventar) const;
    friend std::ostream &operator<<(std::ostream &os, const satean &satean);
};

#endif //OOP_SATEAN_H