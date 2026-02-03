//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_PESTE_H
#define OOP_PESTE_H

#include "item.h"
#include <string>

/**
 * @class peste
 * @brief Subclasă a clasei Item. Peștii pot fi pescuiți și pot fi vânduți la un preț stabilit de
 * masa lor.
 */
class peste : public item {
    std::string nume;
    double greutate;
    std::string locatie;

public:
    peste(const std::string &nume, int sellPrice, const std::string &locatie);

    peste(const peste &other);

    peste &operator=(peste other);

    friend void swap(peste &p1, peste &p2) noexcept;

    [[nodiscard]] item *clone() const override;

    ~peste() override;

    void avansZi() override;

    [[nodiscard]] int calcPret() const override;

    void afis(std::ostream &os) const override;

    void pescuieste();

    [[nodiscard]] double getGreutate() const { return greutate; }
    [[nodiscard]] const std::string &getNume() const override { return nume; }
    double calculeazaEfort() const override;
};

#endif //OOP_PESTE_H
