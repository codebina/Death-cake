//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_PLANTA_H
#define OOP_PLANTA_H

#include <string>
#include <iostream>

class planta {
    std::string nume;
    int z_crestere;
    bool udata;

public:
    planta(const std::string &nume, int z_crestere);
    planta(const planta &other);
    planta &operator=(const planta &other);
    ~planta();

    void set_udata();
    void reset_udata();
    bool gata();
    bool creste();

    [[nodiscard]] bool get_udata() const;
    [[nodiscard]] const std::string& get_nume() const;
    [[nodiscard]] int get_z_crestere() const;

    friend std::ostream &operator<<(std::ostream &os, const planta &planta);
};


#endif //OOP_PLANTA_H