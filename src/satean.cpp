//
// Created by sabin on 11/2/2025.
//
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "../headers/item.h"

template <typename T>
satean<T>::satean(const std::string &nume, const std::string &numeCere, const T &ofera)
    : nume(nume), numeCere(numeCere), ofera(ofera) {
}

template <typename T>
const T &satean<T>::getOfera() const {
    return ofera;
}

template <typename T>
bool satean<T>::troc(std::map<std::string, std::vector<std::unique_ptr<item>>> &inventar) const {
    auto it = inventar.find(numeCere);

    if (it == inventar.end() || it->second.empty()) {
        std::cout << "Nu ai " << numeCere << " in inventar!\n";
        return false;
    }


    std::cout << "Ai " << numeCere << " in inventar. Vrei sa faci schimbul? (1-Da, 0-Nu)\n";

    int optiune;
    if (!(std::cin >> optiune)) {
        std::cin.clear();
        return false;
    }

    if (optiune == 1) {
        std::cout << nume << ": " << "Sarut mana, tinere... Poftim rasplata.\n";
        it->second.pop_back();

        if (it->second.empty()) {
            inventar.erase(it);
        }
        return true;
    }
    return false;
}