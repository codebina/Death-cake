//
// Created by sabin on 11/3/2025.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H
#include <string>
#include <map>

class shop {
    std::string nume;
    std::map<std::string, int> stoc;
public:
    shop(const std::string &nume);
    int calculeaza_pret(const std::string &nume_prod, int cant);
    void adaugare_stoc(const std::string &nume_prod, int pret);
    friend std::ostream &operator<<(std::ostream &os, const shop &shop);
};


#endif //OOP_SHOP_H