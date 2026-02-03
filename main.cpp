#include <iostream>
#include "headers/player.h"
#include "headers/satean.h"
#include "headers/exceptions.h"
#include "headers/itemFactory.h"
#include <limits>
#include "headers/shop.h"

int main() {
    ferma FermaInitiala("Ferma Bunicii");
    player player1("Corporatist jalnic venit la tara", FermaInitiala);
    shop& sh = shop::getInstance();

    auto ptrRosie = itemFactory::createItem("planta", "Rosie");
    auto ptrVarza = itemFactory::createItem("planta", "Varza");
    auto ptrMorcov = itemFactory::createItem("planta", "Morcov");
    auto ptrLeustean = itemFactory::createItem("planta", "Leustean");
    auto ptrGrau = itemFactory::createItem("planta", "Grau");

    planta Rosie = *dynamic_cast<planta*>(ptrRosie.get());
    planta Varza = *dynamic_cast<planta*>(ptrVarza.get());
    planta Morcov = *dynamic_cast<planta*>(ptrMorcov.get());
    planta Leustean = *dynamic_cast<planta*>(ptrLeustean.get());
    planta Grau = *dynamic_cast<planta*>(ptrGrau.get());

    animal Steluta("Steluta", "Vaca", 2);
    player1.adaugaAnimal(Steluta);

    sh.adaugareStoc("Rosie", 10);
    sh.adaugareStoc("Morcov", 8);
    sh.adaugareStoc("Varza", 7);
    sh.adaugareStoc("Leustean", 5);
    sh.adaugareStoc("Grau", 10);

    int alegere;
    bool running = true;
    std::cout << "\nScopul tau este sa faci coliva. Nu stii reteta de coliva traditional!\n";

    while (running) {
        std::cout << "\nActiuni:\n";
        std::cout << "1. Uda plantele\n";
        std::cout << "2. Planteaza\n";
        std::cout << "3. Recolteaza\n";
        std::cout << "4. Cumpara seminte\n";
        std::cout << "5. Afisare stare\n";
        std::cout << "6. Negociaza cu localinicii pentru retete sau iteme speciale :^)\n";
        std::cout << "7. Prepara mancare dupa reteta\n";
        std::cout << "8. Baga-te in paturici\n";
        std::cout << "9. Pescuieste\n";
        std::cout << "10. Colecteaza produse animale\n";
        std::cout << "11. Vinde item\n";
        std::cout << "12. Compara pretul de vanzare a doua iteme\n";
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
                case 1: player1.udaPlante();
                    break;

                case 2: {
                    // Planteaza
                    std::cout << "\nAlege ce vrei sa plantezi:\n" <<
                            "1. Rosie\n2. Morcov\n3. Varza\n4. Leustean\n5. Grau\n";
                    int alegere1;
                    std::cin >> alegere1;
                    switch (alegere1) {
                        case 1: player1.planteaza(Rosie);
                            break;
                        case 2: player1.planteaza(Morcov);
                            break;
                        case 3: player1.planteaza(Varza);
                            break;
                        case 4: player1.planteaza(Leustean);
                            break;
                        case 5: player1.planteaza(Grau);
                            break;
                        default: std::cout << "Optiune invalida!\n";
                            break;
                    }
                }
                break;

                case 3: player1.recolta();
                    break;

                case 4: {
                    // Cumpara Seminte
                    std::cout << sh;
                    std::cout << "\nAlege ce seminte vrei sa cumperi:\n" <<
                            "1. Rosie\n2. Morcov\n3. Varza\n4. Leustean\n5. Grau\n0. Exit\n";
                    int alegere2, cant;
                    std::cin >> alegere2;
                    if (alegere2 == 0) break;

                    std::cout << "Cantitate:\n";
                    std::cin >> cant;

                    switch (alegere2) {
                        case 1: player1.cumparaSeminte(Rosie, cant);
                            break;
                        case 2: player1.cumparaSeminte(Morcov, cant);
                            break;
                        case 3: player1.cumparaSeminte(Varza, cant);
                            break;
                        case 4: player1.cumparaSeminte(Leustean, cant);
                            break;
                        case 5: player1.cumparaSeminte(Grau, cant);
                            break;
                        default: std::cout << "Optiune invalida!\n";
                            break;
                    }
                }
                break;

                case 5: std::cout << player1;
                    break;
                case 6: player1.cautaReteta();
                    break;
                case 7: {
                    auto& reteteCunoscute = player1.getRetete();

                    if (reteteCunoscute.empty()) {
                        std::cout << "Nu stii nicio reteta! Mergi la sateni mai intai.\n";
                        break;
                    }

                    std::cout << "\n--- RETETE CUNOSCUTE ---\n";
                    for (int i = 0; i < static_cast<int>(reteteCunoscute.size()); ++i) {
                        std::cout << i + 1 << ". " << reteteCunoscute[i].getNume() << "\n";
                    }
                    std::cout << "0. Anuleaza\n";
                    std::cout << "Alege numarul retetei: ";

                    int alegereReteta;
                    std::cin >> alegereReteta;

                    if (alegereReteta > 0) {
                        player1.prepara(alegereReteta - 1);
                    }
                    break;
                }
                    break;
                case 8: player1.somnic();
                    break;
                case 9: player1.pescuieste();
                    break;
                case 10: player1.colecteazaProduseAnimale();
                    break;

                case 11: {
                    // Vinde Item
                    std::string nume_item;
                    int cant;
                    std::cout << "Nume item de vandut: ";
                    std::cin >> nume_item;
                    std::cout << "Cantitate: ";
                    std::cin >> cant;
                    player1.vindeItem(nume_item, cant);
                }
                break;
                case 12: {
                    std::string n1, n2;
                    std::cout << "Ce vrei sa compari? (Scrie numele exact, ex: 'Rosie' sau 'Reteta Sarmale de post')\n";
                    std::cout << "Entitate 1: "; std::cin.ignore(); std::getline(std::cin, n1);
                    std::cout << "Entitate 2: "; std::getline(std::cin, n2);

                    player1.compara(n1, n2);
                    break;
                }
                case 0: running = false;
                    break;
                default: std::cout << "Optiune invalida!\n";
                    break;
            }
        } catch (const InsufficientFundsException &e) {
            std::cerr << "BANI INSUFICIENTI: " << e.what() << "\n";
        } catch (const InsufficientEnergyException &e) {
            std::cerr << "ENERGIE SCAZUTA: " << e.what() << "\n";
        } catch (const MissingItemException &e) {
            std::cerr << "ITEM LIPSA: " << e.what() << "\n";
        } catch (const GameException &e) {
            std::cerr << "EROARE JOC GENERICA: " << e.what() << "\n";
        } catch (const std::exception &e) {
            std::cerr << "Fatal Error: " << e.what() << "\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n Mersi ca te ai jucat! :^)\n";
    return 0;
}
