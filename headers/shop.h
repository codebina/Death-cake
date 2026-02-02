//
// Created by sabin on 11/3/2025.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H
#include <string>
#include <map>

/**
 * @class shop
 * @brief Design pattern Singleton. Este un singur magazin de unde se pot achiziționa semințele.
 */
class shop {
    std::string nume;
    std::map<std::string, int> stoc;
    explicit shop(const std::string& nume);

public:
    shop(const shop&) = delete;

    shop& operator=(const shop&) = delete;

    static shop& getInstance();

    int calculeazaPret(const std::string &numeProd, int cant);

    void adaugareStoc(const std::string &numeProd, int pret);

    friend std::ostream &operator<<(std::ostream &os, const shop &shop);
};


#endif //OOP_SHOP_H
