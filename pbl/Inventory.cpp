#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void Inventory::setProducts(const std::vector<Product>& loadedProducts) {
    products = loadedProducts;
}

const std::vector<Product>& Inventory::getProducts() const {
    return products;
}

void Inventory::addProduct(const Product& p) {
    // Sprawdzamy, czy produkt o danym ID juz istnieje
    auto it = std::find_if(products.begin(), products.end(),
                           [&p](const Product& existing) { return existing.id == p.id; });

    if (it != products.end()) {
        it->quantity += p.quantity;
        std::cout << "Produkt " << p.id << " juz istnieje. Zwiekszono ilosc o " << p.quantity << ".\n";
    } else {
        products.push_back(p);
        std::cout << "Dodano nowy produkt: " << p.name << ".\n";
    }
}

bool Inventory::removeProduct(const std::string& id) {
    auto it = std::remove_if(products.begin(), products.end(),
                             [&id](const Product& p) { return p.id == id; });

    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Usunieto produkt o ID: " << id << ".\n";
        return true;
    }
    std::cout << "Nie znaleziono produktu o ID: " << id << ".\n";
    return false;
}

void Inventory::displayAll() const {
    if (products.empty()) {
        std::cout << "Magazyn jest pusty.\n";
        return;
    }

    std::cout << std::left 
              << std::setw(10) << "ID" 
              << std::setw(25) << "Nazwa" 
              << std::setw(10) << "Ilosc" 
              << std::setw(10) << "Jedn." 
              << std::setw(15) << "Lokalizacja" << "\n";
    std::cout << std::string(70, '-') << "\n";

    for (const auto& p : products) {
        std::cout << std::left 
                  << std::setw(10) << p.id 
                  << std::setw(25) << p.name 
                  << std::setw(10) << p.quantity 
                  << std::setw(10) << p.unit 
                  << std::setw(15) << p.location << "\n";
    }
}