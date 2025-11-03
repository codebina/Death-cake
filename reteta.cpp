//
// Created by sabin on 11/2/2025.
//

#include "reteta.h"

reteta::reteta(const std::string &nume, const std::map<std::string, int> &ingrediente):
nume(nume), ingrediente(ingrediente){}


bool reteta::prepara(const std::map<std::string, int> &inventar) const {
    for (const auto &[item, cant] : ingrediente) {
        if (inventar.count(item) == 0 || inventar.at(item) < cant) {
            std::cout<<"Reteta de "<<nume<<" nu se poate prepara. Nu ai toate ingredientele!\n";
            return false;
        }

    }
    std::cout<<"Felicitari! Ai reusit sa prepari: "<<nume<<"!\n";
    return true;
}
const std::string& reteta::get_nume () const {return nume;}

std::ostream &operator<<(std::ostream &os, const reteta &reteta) {
    os<<"Reteta de "<<reteta.nume<<"\n";
    os<<"Ingrediente:\n";
    for (const auto&[item, cant] : reteta.ingrediente) {
        os<<item<<" x "<<cant<<"\n ";
    }
    return os;
}


