#include <iostream>
#include "player.h"
#include "satean.h"

int main() {
    player player1("Corporatist jalnic venit la tara", ferma("Ferma Bunicii"));

    player1.planteaza(planta("Rosie", 3));
    player1.planteaza(planta("Morcov", 2));
    player1.planteaza(planta("Varza", 2));

    reteta sarmale_post("Sarmale de post", {{"Varza", 2} ,{"Morcov", 1}});
    int alegere;
    bool running = true;
    std::cout<<"\nScopul tau este sa faci sarmale de post. Nu stii reteta de sarmale de post!\n";
    while (running) {
        std::cout << "\nActiuni:\n";
        std::cout << "1. Uda plantele\n";
        std::cout << "2. Odihneste-te\n";
        std::cout << "3. Recolteaza\n";
        std::cout << "4. Afisare stare\n";
        std::cout << "5. Negociaza cu localinicii pentru reteta\n";
        std::cout << "6. Prepara sarmale de post dupa reteta\n";
        std::cout << "0. Iesi\n";
        std::cout << "Alegere: ";
        std::cin >> alegere;

        switch (alegere) {
            case 1: player1.uda_plante(); break;
            case 2: player1.somnic(); break;
            case 3: player1.recolta(); break;
            case 4: std::cout << player1; break;
            case 5: player1.cauta_reteta(); break;
            case 6: player1.prepara(sarmale_post); break;
            case 0: running = false; break;
            default: std::cout << "Optiune invalida!\n"; break;
        }
    }

    return 0;
}
