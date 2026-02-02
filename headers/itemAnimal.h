//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_ITEMANIMAL_H
#define OOP_ITEMANIMAL_H
#include <string>
#include <iostream>
#include "item.h"

/**
 * @class itemAnimal
 * @brief Subclasă a clasei Item. Valoarea prețului îi scade în funcție de prospețime,
 valoare ce scade cu timpul.
 */

class itemAnimal : public item {
    std::string nume;
    std::string provineAnimal;
    int prospetime;

public:
    itemAnimal(const std::string &nume, const std::string &provineAnimal, int sellPrice);

    itemAnimal(const itemAnimal &other);

    itemAnimal &operator=(itemAnimal other);

    friend void swap(itemAnimal &a1, itemAnimal &a2) noexcept;

    [[nodiscard]] item *clone() const override;

    ~itemAnimal() override;

    void avansZi() override;

    [[nodiscard]] int calcPret() const override;

    void afis(std::ostream &os) const override;

    [[nodiscard]] const std::string &getNume() const override { return nume; }

    double calculeazaEfort() const override;
};


#endif //OOP_ITEMANIMAL_H
