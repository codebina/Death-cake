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
    std::map<std::string,int> ingrediente;
public:
    reteta(const std::string &nume, const std::map<std::string, int> & ingediente);
    bool prepara(std::map<std::string, std::vector<std::unique_ptr<item>>>& inventar)const;
    [[nodiscard]] const std::string& get_nume () const;
    friend std::ostream &operator<<(std::ostream &os, const reteta& reteta);
};


#endif //OOP_RETETA_H