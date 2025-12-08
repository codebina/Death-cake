//
// Created by sabin on 12/7/2025.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <iostream>

class item {
protected:
    int sell_price;

public:
    explicit item(int sell_price);
    virtual ~item() = default;
    [[nodiscard]]virtual item* clone() const = 0;
    [[nodiscard]]virtual const std::string& get_nume() const = 0;
    virtual void avans_zi() = 0;
    [[nodiscard]]virtual int calcPret() const=0;
    virtual void afis(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const item &it);
};
#endif //OOP_ITEM_H