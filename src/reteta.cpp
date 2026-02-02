//
// Created by sabin on 11/2/2025.
//

#include "../headers/reteta.h"
#include "../headers/exceptions.h"
#include "../headers/mancareGatita.h"

reteta::reteta(const std::string &nume, const std::map<std::string, int> &ingrediente) : nume(nume),
    ingrediente(ingrediente) {
}


std::unique_ptr<item> reteta::prepara(std::map<std::string, std::vector<std::unique_ptr<item> > > &inventar) const {
    for (const auto &[itemNecesar, cantNecesara]: ingrediente) {
        auto it = inventar.find(itemNecesar);

        if (it == inventar.end() || it->second.size() < static_cast<std::size_t>(cantNecesara)) {
            throw MissingItemException(itemNecesar + " (necesar: " + std::to_string(cantNecesara) +
                                       ", ai: " + (it == inventar.end() ? "0" : std::to_string(it->second.size())) +
                                       ")");
        }
    }

    for (const auto &[itemNecesar, cantNecesara]: ingrediente) {
        auto it = inventar.find(itemNecesar);
        for (int i = 0; i < cantNecesara; ++i) {
            it->second.pop_back();
        }
        if (it->second.empty()) {
            inventar.erase(it);
        }
    }
    constexpr int pretFixVanzare = 150;

    auto preparat = std::make_unique<mancareGatita>(nume, pretFixVanzare);

    std::cout << "Felicitari! Ai reusit sa prepari: " << nume << "!\n";

    return preparat;
}

const std::string &reteta::getNume() const { return nume; }

std::ostream &operator<<(std::ostream &os, const reteta &reteta) {
    os << "Reteta de " << reteta.nume << "\n";
    os << "Ingrediente:\n";
    for (const auto &[item, cant]: reteta.ingrediente) {
        os << item << " x " << cant << "\n ";
    }
    return os;
}
