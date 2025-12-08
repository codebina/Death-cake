//
// Created by sabin on 12/8/2025.
//

#ifndef OOP_MANCAREGATITA_H
#define OOP_MANCAREGATITA_H

#include "item.h"
#include <string>

class mancareGatita : public item {
private:
    std::string nume;
public:
    mancareGatita(const std::string& nume, int sell_price);
    [[nodiscard]]const std::string& get_nume() const override;
    void afis(std::ostream &os) const override;
    [[nodiscard]]item* clone() const override;
    [[nodiscard]]int calcPret() const override;
    void avans_zi() override;
};


#endif //OOP_MANCAREGATITA_H