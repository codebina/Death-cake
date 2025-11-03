#include <iostream>
#include "player.h"
#include "satean.h"

int main() {
    player player1("Corporatist jalnic venit la tara", ferma("Ferma Bunicii"));

    //cc si op= apelate ca sa arat ca functioneaza:

    planta Rosie("Rosie", 3);
    planta copie_Rosie(Rosie);
    planta Ardei("Ardei", 1);
    Ardei=Rosie;
    planta Morcov("Morcov", 2);
    planta Varza("Varza", 2);
    planta Leustean("Leustean", 5);

    reteta sarmale_post("Sarmale de post", {{"Varza", 2} ,{"Morcov", 1}});
    shop sh("Magazin Seminte");

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
        std::cout << "8. Odihneste-te\n";
        std::cout << "0. Iesi\n";
        std::cout << "Alegere: ";
        std::cin >> alegere;

        switch (alegere) {
            case 1: player1.uda_plante(); break;
            case 2: {
                std::cout<<"Alege ce vrei sa plantezi:\n"<<
            "1. Rosie\n 2.Morcov \n 3. Varza\n 4. Leustean \n";
                int alegere1;
                std::cin >> alegere1;
                switch (alegere1) {
                    case 1: player1.planteaza(Rosie); break;
                    case 2: player1.planteaza(Morcov); break;
                    case 3: player1.planteaza(Varza); break;
                    case 4: player1.planteaza(Leustean); break;
                    default: std::cout << "Optiune invalida!\n"; break;
                }
            }; break;
            case 3: player1.recolta(); break;
            case 4: {
                std::cout<<sh;
                std::cout<<"Alege ce seminte vrei sa cumperi:\n"<<
            "1. Rosie\n 2.Morcov \n 3. Varza\n 4. Leustean\n 0.Exit \n";
                int alegere2, cant;
                std::cin >> alegere2;
                switch (alegere2) {
                    case 1:{ std::cout<<"Cantitate:\n"; std::cin>>cant;
                        player1.cumpara_seminte(Rosie,cant, sh);} break;
                    case 2: { std::cout<<"Cantitate:\n"; std::cin>>cant;
                        player1.cumpara_seminte(Morcov, cant, sh);} break;
                    case 3: { std::cout<<"Cantitate:\n"; std::cin>>cant;
                        player1.cumpara_seminte(Varza, cant, sh); break;
                    case 4: { std::cout<<"Cantitate:\n"; std::cin>>cant;
                        player1.cumpara_seminte(Leustean, cant, sh);} break;
                    case 0: break;
                    default: std::cout << "Optiune invalida!\n"; break;
                    }
                }
            } break;
                case 5: std::cout << player1; break;
                case 6: player1.cauta_reteta(); break;
                case 7: player1.prepara(sarmale_post); break;
                case 8: player1.somnic(); break;
                case 0: running = false; break;
                default: std::cout << "Optiune invalida!\n"; break;
            }
        }

    return 0;
}


