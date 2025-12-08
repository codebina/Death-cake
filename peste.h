//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_PESTE_H
#define OOP_PESTE_H

#include "item.h"
#include <string>

class peste : public item {
    std::string nume;
    double greutate;
    std::string locatie;

public:
    peste(const std::string &nume, int sell_price,const std::string &locatie );
    peste(const peste &other);
    peste &operator=(peste other);
    friend void swap(peste &p1, peste &p2) noexcept;
    [[nodiscard]] item* clone() const override;
    ~peste() override;
    void avans_zi() override;
    [[nodiscard]] int calcPret() const override;
    void afis(std::ostream &os) const override;
    void pescuieste();
    [[nodiscard]] double get_greutate() const { return greutate; }
    [[nodiscard]] const std::string& get_locatie() const { return locatie; }
    [[nodiscard]] const std::string& get_nume() const override { return nume; }
};

#endif //OOP_PESTE_H