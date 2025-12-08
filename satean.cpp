//
// Created by sabin on 11/2/2025.
//

#include "satean.h"

satean::satean(const std::string&nume, const std::string &nume_cere, const reteta &ofera ) :
nume(nume), nume_cere(nume_cere), ofera(ofera) {}

const reteta &satean:: get_ofera() const {
    return ofera;
}
bool satean::troc(std::map<std::string, std::vector<std::unique_ptr<item>>>& inventar) const{
    auto it = inventar.find(nume_cere);

    if (it == inventar.end() || it->second.empty()) {
        std::cout << "Nu ai " << nume_cere << " in inventar!\n";
        return false;
    }
    std::cout<<"Ai "<<nume_cere<<" in inventar. Vrei sa oferi "<<nume_cere<<
        " in schimbul retetei de "<<ofera.get_nume()<<"?\n"<<" Da(1) sau Nu(0)?\n";
    int optiune;
    std::cin>>optiune;
    if (optiune) {
        std::cout << nume << ": "<<"Sarut mana, tinere..."
        << " Poftim reteta mea pentru " << ofera.get_nume() << ".\n";
        it->second.pop_back();

        // Curăță intrarea din mapă dacă vectorul devine gol
        if (it->second.empty()) {
            inventar.erase(it);
        }
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os,const satean &satean){
        os<<satean.nume<<" ofera reteta de "<<satean.ofera.get_nume()<<" in schimbul plantei: "
        <<satean.nume_cere<<".\n";
        return os;
}






