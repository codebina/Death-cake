//
// Created by sabin on 12/8/2025.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H


#include <iostream>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& msg) : std::runtime_error(msg) {}

};

class InsufficientFundsException : public GameException {
public:
    explicit InsufficientFundsException(const std::string& item);
};

class InsufficientEnergyException : public GameException {
public:
    explicit InsufficientEnergyException(const std::string& action);
};

class MissingItemException : public GameException {
public:
    explicit MissingItemException(const std::string& item_name);
};


#endif //OOP_EXCEPTIONS_H