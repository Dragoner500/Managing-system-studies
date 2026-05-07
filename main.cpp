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

    inventory.setProducts(storage.loadProducts());

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== SYSTEM MAGAZYNOWY ===\n";
        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj NOWY produkt\n";
        std::cout << "3. Zwieksz ilosc ISTNIEJACEGO produktu\n";
        std::cout << "4. Usun produkt\n";
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
                
            case 2: { // Dodawanie nowego produktu z limitami długości
                std::string id, name, unit, location;
                int qty;

                // Zabezpieczenie długości ID
                while (true) {
                    std::cout << "\nPodaj ID produktu (max 8 znakow): ";
                    std::cin >> id;
                    if (id.length() > 8) {
                        std::cout << "ID jest za dlugie! Sprobuj ponownie.\n";
                    } else {
                        break;
                    }
                }
                clearBuffer();

                // Zabezpieczenie długości Nazwy
                while (true) {
                    std::cout << "Podaj nazwe (max 22 znaki): ";
                    std::getline(std::cin, name);
                    if (name.length() > 22) {
                        std::cout << "Nazwa jest za dluga! Sprobuj ponownie.\n";
                    } else {
                        break;
                    }
                }

                std::cout << "Podaj poczatkowa ilosc: ";
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
            
            case 3: { // Dodawanie sztuk do istniejącego produktu
                std::string id;
                int amount;
                
                std::cout << "\nPodaj ID produktu, ktorego stan chcesz zwiekszyc: ";
                std::cin >> id;
                
                std::cout << "Ile sztuk/jednostek chcesz dodac?: ";
                while (!(std::cin >> amount)) {
                    clearBuffer();
                    std::cout << "To nie jest liczba! Podaj ilosc: ";
                }
                
                inventory.addQuantity(id, amount);
                break;
            }
            
            case 4: { // Usuwanie
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