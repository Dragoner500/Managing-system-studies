#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "json.hpp" // Lokalny plik biblioteki

using json = nlohmann::json;

struct Product {
    std::string id;
    std::string name;
    int quantity;
    std::string unit;
    std::string location;

    // Konstruktor domyślny wymagany przez bibliotekę JSON
    Product() : quantity(0) {}

    // Konstruktor ułatwiający tworzenie obiektów
    Product(std::string id, std::string name, int qty, std::string unit, std::string loc)
        : id(id), name(name), quantity(qty), unit(unit), location(loc) {}
};

// Makro mapujące strukturę na JSON i odwrotnie
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Product, id, name, quantity, unit, location)

#endif // PRODUCT_H
