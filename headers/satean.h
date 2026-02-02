//
// Created by sabin on 11/2/2025.
//

#ifndef OOP_SATEAN_H
#define OOP_SATEAN_H

#include "item.h"
#include "reteta.h"

#include <map>
#include <string>
#include <vector>
#include <memory>

/**
 * @class satean
 * @brief Clasă șablon pentru a permite unui sătean să ofere ori o rețetă, ori un item.
 */
template <typename T>
class satean {
    std::string nume;
    std::string numeCere;
    T ofera;

public:
    satean(const std::string &nume, const std::string &cere, const T &ofera);

    [[nodiscard]] const T &getOfera() const;

    bool troc(std::map<std::string, std::vector<std::unique_ptr<item> > > &inventar) const;

    friend std::ostream &operator<<(std::ostream &os, const satean<T> &s) {
        os << s.nume << " vrea " << s.numeCere << " la schimb.";
        return os;
    }
};
#include "../src/satean.cpp"
#endif //OOP_SATEAN_H
