#include <iostream>
#include "player.h"
#include "satean.h"
#include "exceptions.h"
#include <limits>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    ferma FermaInitiala("Ferma Bunicii");
    player player1("Corporatist jalnic venit la tara", FermaInitiala);
    shop sh("Magazin Seminte");

    planta Rosie("Rosie", 3, 10);
    planta Varza("Varza", 2, 7);
    planta Morcov("Morcov", 4, 15);
    planta Leustean("Leustean", 5, 20); // Definim Leustean pentru meniu

    animal Steluta("Steluta", "Vaca", 2);
    player1.adauga_animal(Steluta);

    reteta sarmale_post("Sarmale de post", {{"Varza", 2} ,{"Morcov", 1}});

    sh.adaugare_stoc("Rosie", 10);
    sh.adaugare_stoc("Morcov", 8);
    sh.adaugare_stoc("Varza", 7);
    sh.adaugare_stoc("Leustean", 5);

    int alegere;
    bool running = true;
    std::cout<<"\nScopul tau este sa faci sarmale de post. Nu stii reteta de sarmale de post!\n";

    while (running) {
        std::cout << "\nActiuni:\n";
        std::cout << "1. Uda plantele\n";
        std::cout << "2. Planteaza\n";
        std::cout << "3. Recolteaza\n";
        std::cout << "4. Cumpara seminte\n";
        std::cout << "5. Afisare stare\n";
        std::cout << "6. Negociaza cu localinicii pentru reteta\n";
        std::cout << "7. Prepara sarmale de post dupa reteta\n";
        std::cout << "8. Baga-te in paturici\n";
        std::cout << "9. Pescuieste\n";
        std::cout << "10. Colecteaza produse animale\n";
        std::cout << "11. Vinde item\n";
        std::cout << "0. Iesi\n";
        std::cout << "Alegere: ";

        if (!(std::cin >> alegere)) {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout << "Optiune invalida.\n";
             continue;
        }

        try {
            switch (alegere) {
                case 1: player1.uda_plante(); break;

                case 2: { // Planteaza
                    std::cout<<"\nAlege ce vrei sa plantezi:\n"<<
                    "1. Rosie\n2. Morcov\n3. Varza\n4. Leustean\n";
                    int alegere1;
                    std::cin >> alegere1;
                    switch (alegere1) {
                        case 1: player1.planteaza(Rosie); break;
                        case 2: player1.planteaza(Morcov); break;
                        case 3: player1.planteaza(Varza); break;
                        case 4: player1.planteaza(Leustean); break;
                        default: std::cout << "Optiune invalida!\n"; break;
                    }
                } break;

                case 3: player1.recolta(); break;

                case 4: { // Cumpara Seminte
                    std::cout<<sh;
                    std::cout<<"\nAlege ce seminte vrei sa cumperi:\n"<<
                    "1. Rosie\n2. Morcov\n3. Varza\n4. Leustean\n0. Exit\n";
                    int alegere2, cant;
                    std::cin >> alegere2;
                    if (alegere2 == 0) break;

                    std::cout<<"Cantitate:\n"; std::cin>>cant;

                    switch (alegere2) {
                        case 1: player1.cumpara_seminte(Rosie, cant, sh); break;
                        case 2: player1.cumpara_seminte(Morcov, cant, sh); break;
                        case 3: player1.cumpara_seminte(Varza, cant, sh); break;
                        case 4: player1.cumpara_seminte(Leustean, cant, sh); break;
                        default: std::cout << "Optiune invalida!\n"; break;
                    }
                } break;

                case 5: std::cout << player1; break;
                case 6: player1.cauta_reteta(); break;
                case 7: player1.prepara(sarmale_post); break;
                case 8: player1.somnic(); break;
                case 9: player1.pescuieste(); break;
                case 10: player1.colecteaza_produse_animale(); break;

                case 11: { // Vinde Item
                    std::string nume_item;
                    int cant;
                    std::cout << "Nume item de vandut: ";
                    std::cin >> nume_item;
                    std::cout << "Cantitate: ";
                    std::cin >> cant;
                    player1.vinde_item(nume_item, cant);
                } break;

                case 0: running = false; break;
                default: std::cout << "Optiune invalida!\n"; break;
            }
        }

        catch (const InsufficientFundsException& e) {
            std::cerr << "BANI INSUFICIENTI: " << e.what() << "\n";
        }
        catch (const InsufficientEnergyException& e) {
            std::cerr << "ENERGIE SCAZUTA: " << e.what() << "\n";
        }
        catch (const MissingItemException& e) {
            std::cerr << "ITEM LIPSA: " << e.what() << "\n";
        }
        catch (const GameException& e) {
            std::cerr << "EROARE JOC GENERICA: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Fatal Error: " << e.what() << "\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n Mersi ca te ai jucat! :^)\n";
    return 0;
}

