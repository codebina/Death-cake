//
// Created by sabin on 12/7/2025.
//

#include "../headers/item.h"

item::item(int sellPrice) : sellPrice(sellPrice) {
}

std::ostream &operator<<(std::ostream &os, const item &it) {
    it.afis(os);
    return os;
}
