#include <iostream>
#include <string>
#include <limits>
#include "Product.h"
#include "Inventory.h"
#include "Storage.h"

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Storage storage("magazyn_dane.json");
    Inventory inventory;

    // Pobranie danych na starcie programu
    inventory.setProducts(storage.loadProducts());

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== SYSTEM MAGAZYNOWY ===\n";
        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj produkt\n";
        std::cout << "3. Usun produkt\n";
        std::cout << "0. Zapisz i Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        
        if (!(std::cin >> choice)) {
            clearBuffer();
            std::cout << "Nieprawidlowy wybor!\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\n--- STAN MAGAZYNU ---\n";
                inventory.displayAll();
                break;
            case 2: {
                std::string id, name, unit, location;
                int qty;

                std::cout << "\nPodaj ID produktu: ";
                std::cin >> id;
                clearBuffer(); // Czyszczenie bufora przed getline

                std::cout << "Podaj nazwe: ";
                std::getline(std::cin, name);

                std::cout << "Podaj ilosc: ";
                while (!(std::cin >> qty)) {
                    clearBuffer();
                    std::cout << "To nie jest liczba! Podaj ilosc: ";
                }

                std::cout << "Podaj jednostke (np. szt, kg): ";
                std::cin >> unit;

                clearBuffer();
                std::cout << "Podaj lokalizacje: ";
                std::getline(std::cin, location);

                inventory.addProduct(Product(id, name, qty, unit, location));
                break;
            }
            case 3: {
                std::string id;
                std::cout << "\nPodaj ID produktu do usuniecia: ";
                std::cin >> id;
                inventory.removeProduct(id);
                break;
            }
            case 0:
                std::cout << "Zapisywanie danych...\n";
                storage.saveProducts(inventory.getProducts());
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
    }

    return 0;
}