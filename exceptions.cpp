//
// Created by sabin on 12/8/2025.
//

#include "exceptions.h"

InsufficientFundsException::InsufficientFundsException(const std::string& item)
    : GameException("Nu ai destui bani pentru a cumpara " + item + ".")
{}

InsufficientEnergyException::InsufficientEnergyException(const std::string& action)
    : GameException("Nu ai destula energie pentru a " + action + ".")
{}

MissingItemException::MissingItemException(const std::string& item_name)
    : GameException("Nu ai destule iteme de felul: " + item_name + " in inventar sau seminte.")
{}