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

class satean {
    std::string nume;
    std::string nume_cere;
    reteta ofera;
    public:
    satean(const std::string &nume, const std::string &cere, const reteta &ofera);
    [[nodiscard]] const reteta &get_ofera() const;
    bool troc(std::map<std::string, std::vector<std::unique_ptr<item>>>& inventar) const;

    friend std::ostream &operator<<(std::ostream &os, const satean &satean);
};

#endif //OOP_SATEAN_H