//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <iostream>
/**
 * @class item
 * @brief Clasa abstracta de baza pentru toate obiectele din joc.
 * * Defineste interfata comuna pentru plante, resurse animale, pesti si mancare,
 * obligand subclasele sa implementeze calculul efortului si al pretului.
 */
class item {
protected:
    int sellPrice;

public:
    explicit item(int sellPrice);

    virtual ~item() = default;

    [[nodiscard]] virtual item *clone() const = 0;

    [[nodiscard]] virtual const std::string &getNume() const = 0;

    virtual void avansZi() = 0;

    [[nodiscard]] virtual int calcPret() const =0;

    /**
     *@brief Calculează efortul necesar pentru a colecta/prepara itemul.
     * @return O valoare diferită pentru fiecare tip de item.
     */
    virtual double calculeazaEfort() const = 0;

    virtual void afis(std::ostream &os) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const item &it);
};
#endif //OOP_ITEM_H
