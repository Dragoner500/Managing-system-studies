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
    
    void addProduct(const Product& newProduct);
    bool removeProduct(const std::string& id);
    void displayAll() const;
};

#endif // INVENTORY_H
