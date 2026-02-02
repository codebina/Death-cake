
#ifndef OOP_ITEMFACTORY_H
#define OOP_ITEMFACTORY_H

#include <memory>
#include <string>
#include "item.h"
/**
 * @class itemFactory
 * @brief Design Pattern Factory. Se pot genera tote tipurile de iteme.
 */
class itemFactory {
public:

    static std::unique_ptr<item> createItem(const std::string& tipItem, const std::string& numeSpecifc);
};

#endif //OOP_ITEMFACTORY_H