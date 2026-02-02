//
// Created by sabin on 12/8/2025.
//

#ifndef OOP_MANCAREGATITA_H
#define OOP_MANCAREGATITA_H

#include "item.h"
#include <string>

/**
 * @class mancareGatita
 * @brief Subclasa a clasei Item. Mancarea gatita este obtinuta cu ajutorul unei retete
 * si se poate prepara doar daca jucatorul are toate ingredientele necesare in inventar.
 */
class mancareGatita : public item {
private:
    std::string nume;

public:
    mancareGatita(const std::string &nume, int sellPrice);

    [[nodiscard]] const std::string &getNume() const override;

    void afis(std::ostream &os) const override;

    [[nodiscard]] item *clone() const override;

    [[nodiscard]] int calcPret() const override;

    void avansZi() override;

    double calculeazaEfort() const override;
};


#endif //OOP_MANCAREGATITA_H
