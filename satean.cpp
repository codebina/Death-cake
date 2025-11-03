//
// Created by sabin on 11/2/2025.
//

#include "satean.h"

satean::satean(const std::string&nume, const planta &cere, const reteta &ofera ) :
nume(nume), cere(cere), ofera(ofera) {}

reteta satean::get_ofera() const {
    return ofera;
}
bool satean::troc(const std::map<std::string, int>&inventar) const {
    auto i = inventar.find(cere.get_nume());

    if (i == inventar.end() || i ->second <= 0) {
        std::cout << "Nu ai " << cere.get_nume() << " in inventar!\n";
        return false;
    }
    std::cout<<"Ai "<<cere.get_nume()<<" in inventar. Vrei sa oferi "<<cere.get_nume()<<
        " in schimbul retetei de "<<ofera.get_nume()<<"?\n"<<" Da(1) sau Nu(0)?\n";
    int optiune;
    std::cin>>optiune;
    if (optiune) {
        std::cout << nume << ": "<<"Sarut mana, tinere..."
        << " Poftim reteta mea pentru " << ofera.get_nume() << ".\n";
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os,const satean &satean){
        os<<satean.nume<<" ofera reteta de "<<satean.ofera.get_nume()<<" in schimbul plantei: "
        <<satean.cere.get_nume()<<".\n";
        return os;
}






