//
// Created by sabin on 11/2/2025.
//

#include "reteta.h"
#include "exceptions.h"
reteta::reteta(const std::string &nume, const std::map<std::string, int> &ingrediente):
nume(nume), ingrediente(ingrediente){}


bool reteta::prepara(std::map<std::string, std::vector<std::unique_ptr<item>>>& inventar) const {
    for (const auto &[item_necesar, cant_necesara] : ingrediente)
    {
        auto it = inventar.find(item_necesar);

        if (it == inventar.end() || it->second.size() < static_cast<std::size_t>(cant_necesara)) {
            throw MissingItemException(item_necesar + " (necesar: " + std::to_string(cant_necesara) +
                                       ", ai: " + (it == inventar.end() ?
                                           "0" : std::to_string(it->second.size())) + ")");
        }
    }

    std::cout << "Felicitari! Ai reusit sa prepari: " << nume << "!\n";

    for (const auto &[item_necesar, cant_necesara] : ingrediente) {
        auto it = inventar.find(item_necesar);
        for (int i = 0; i < cant_necesara; ++i) {
            it->second.pop_back();
        }
        if (it->second.empty()) {
            inventar.erase(it);
        }
    }
    return true;
}
const std::string& reteta::get_nume () const {return nume;}

std::ostream &operator<<(std::ostream &os, const reteta &reteta) {
    os<<"Reteta de "<<reteta.nume<<"\n";
    os<<"Ingrediente:\n";
    for (const auto&[item, cant] : reteta.ingrediente) {
        os<<item<<" x "<<cant<<"\n ";
    }
    return os;
}


