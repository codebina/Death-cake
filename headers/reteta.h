//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_RETETA_H
#define OOP_RETETA_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "item.h"

class reteta {
    std::string nume;
    std::map<std::string, int> ingrediente;

public:
    reteta(const std::string &nume, const std::map<std::string, int> &ingediente);

    std::unique_ptr<item> prepara(std::map<std::string, std::vector<std::unique_ptr<item> > > &inventar) const;

    [[nodiscard]] const std::string &getNume() const;

    friend std::ostream &operator<<(std::ostream &os, const reteta &reteta);

    int calcPret() const {
        // Pretul unei retete gata preparate
        return 150;
    }

};


#endif //OOP_RETETA_H
