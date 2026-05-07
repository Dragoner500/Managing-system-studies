#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Product.h"

class Inventory {
private:
    std::vector<Product> products;

public:
    void setProducts(const std::vector<Product>& loadedProducts);
    const std::vector<Product>& getProducts() const;
    
    // Zmienione i dodane funkcje
    bool addProduct(const Product& newProduct);
    bool addQuantity(const std::string& id, int amountToAdd);
    
    bool removeProduct(const std::string& id);
    void displayAll() const;
};

#endif // INVENTORY_H