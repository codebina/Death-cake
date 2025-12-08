//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLANTA_H
#define OOP_PLANTA_H

#include <string>
#include <iostream>
#include "item.h"

class planta : public item{
    std::string nume;
    int z_crestere;
    bool udata;
    int prospetime;

public:
    planta(const std::string &nume, int z_crestere,int sell_price);
    planta(const planta &other);
    planta &operator=(planta other);
    friend void swap(planta& pl1, planta& pl2)noexcept;
    [[nodiscard]] item* clone() const override;
    ~planta()override;

    void set_udata();
    void reset_udata();
    [[nodiscard]] bool gata () const;
    bool creste();

    [[nodiscard]] bool get_udata() const;
    [[nodiscard]] const std::string& get_nume() const override;
    [[nodiscard]] int get_z_crestere() const;
    void avans_zi() override;
    [[nodiscard]] int calcPret() const override;
    void afis(std::ostream& os) const override;
};


#endif //OOP_PLANTA_H