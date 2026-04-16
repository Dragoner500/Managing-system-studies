#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "Product.h"

class Storage {
private:
    std::string filename;

public:
    Storage(const std::string& file);
    std::vector<Product> loadProducts();
    void saveProducts(const std::vector<Product>& products);
};

#endif // STORAGE_H