//
// Created by sabin on 12/7/2025.
//

#include "item.h"

item::item(int sell_price) : sell_price(sell_price) {}

std::ostream& operator<<(std::ostream& os, const item &it) {
    it.afis(os);  // apeleaza functia virtuala din derivat
    return os;
}
