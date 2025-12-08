//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_ITEMANIMAL_H
#define OOP_ITEMANIMAL_H
#include <string>
#include <iostream>
#include "item.h"


class itemAnimal : public item{
    std::string nume;
    std::string provine_animal;
    int prospetime;

public:

    itemAnimal(const std::string &nume, const std::string &provine_animal, int sell_price);
    itemAnimal(const itemAnimal &other);
    itemAnimal& operator=(itemAnimal other);
    friend void swap(itemAnimal &a1, itemAnimal &a2) noexcept;
    [[nodiscard]] item* clone() const override;
    ~itemAnimal() override;
    void avans_zi() override;
    [[nodiscard]] int calcPret() const override;
    void afis(std::ostream &os) const override;
    [[nodiscard]] const std::string& get_nume() const override { return nume; }
};


#endif //OOP_ITEMANIMAL_H