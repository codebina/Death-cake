//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLANTA_H
#define OOP_PLANTA_H

#include <string>
#include <iostream>
#include "item.h"

/**
 * @class planta
 * @brief Subclasă a clasei Item. Plantele pot fi udate, plantate și cresc
 * odată ce trec zilele. După ce trec toate zilele de creștere, pot fi recoltate.
 */
class planta : public item {
    std::string nume;
    int zCrestere;
    bool udata;
    int prospetime;

public:
    planta(const std::string &nume, int zCrestere, int sellPrice);

    planta(const planta &other);

    planta &operator=(planta other);

    friend void swap(planta &pl1, planta &pl2) noexcept;

    [[nodiscard]] item *clone() const override;

    ~planta() override;

    void setUdata();

    void resetUdata();

    [[nodiscard]] bool gata() const;

    bool creste();

    [[nodiscard]] bool getUdata() const;

    [[nodiscard]] const std::string &getNume() const override;

    [[nodiscard]] int getZCrestere() const;

    void avansZi() override;

    [[nodiscard]] int calcPret() const override;

    double calculeazaEfort() const override;

    void afis(std::ostream &os) const override;
};


#endif //OOP_PLANTA_H
