#include "Storage.h"
#include <fstream>
#include <iostream>

Storage::Storage(const std::string& file) : filename(file) {}

std::vector<Product> Storage::loadProducts() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return {}; // Brak pliku, zwracamy pustą listę
    }

    json j;
    try {
        file >> j;
        return j.get<std::vector<Product>>();
    } catch (const json::exception& e) {
        std::cerr << "Blad odczytu pliku JSON: " << e.what() << "\n";
        return {};
    }
}

void Storage::saveProducts(const std::vector<Product>& products) {
    std::ofstream file(filename);
    if (file.is_open()) {
        json j = products;
        file << j.dump(4); // 4 to wcięcia (ładne formatowanie)
    } else {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!\n";
    }
}
