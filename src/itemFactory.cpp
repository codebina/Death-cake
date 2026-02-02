//
// Created by sabin on 2/2/2026.
//

#include "../headers/itemFactory.h"
#include "../headers/planta.h"
#include "../headers/itemAnimal.h"
#include "../headers/peste.h"
#include "../headers/mancareGatita.h"

std::unique_ptr<item> itemFactory::createItem(const std::string& tipItem, const std::string& numeSpecific) {
    if (tipItem == "planta") {
        if (numeSpecific == "Rosie")
            return std::make_unique<planta>("Rosie", 3, 10);
        if (numeSpecific == "Varza")
            return std::make_unique<planta>("Varza", 2, 7);
        if (numeSpecific == "Morcov")
            return std::make_unique<planta>("Morcov", 4, 15);
        if (numeSpecific == "Leustean")
            return std::make_unique<planta>("Leustean", 5, 20);
        if (numeSpecific == "Grau") return std::make_unique<planta>("Grau", 2, 12);
        if (numeSpecific == "Nuca Sfintita")
            return std::make_unique<planta>("Nuca Sfintita", 0, 150);
    }

    if (tipItem == "animal") {
        if (numeSpecific == "Lapte")
            return std::make_unique<itemAnimal>("Lapte", "Vaca", 50);
        if (numeSpecific == "Ou")
            return std::make_unique<itemAnimal>("Ou", "Gaina", 20);
    }

    if (tipItem == "peste") {
        if (numeSpecific == "Crap")
            return std::make_unique<peste>("Crap", 50, "Balta");
        if (numeSpecific == "Somon")
            return std::make_unique<peste>("Somon", 80, "Rau");
    }
    if (tipItem == "mancare") {
        return std::make_unique<mancareGatita>(numeSpecific, 150);
    }

    return nullptr;
}