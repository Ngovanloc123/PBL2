#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "customer.h"
#include "LinkedList.h"
#include "dog.h"
#include "cat.h"


using namespace std;


class FileManager {
public:
    static vector<Customer*> loadFromFile(const string& filename);
    static void saveToFile(const string& filename, const vector<Customer*>& customer);

    static void saveToFileDog(const string& filename, LinkedList<Dog> dogList);
    static void saveToFileCat(const string& filename, LinkedList<Cat> catList);
    // static vector<Product*> loadProductFromFile(const string& filename);
    // static void saveProductToFile(const string& filename, const vector<Product*>& products);
    // static vector<Cart*> loadCartFromFile(const string& filename);
    // static void saveCartToFile(const string& filename, const vector<Cart*>& carts);
};
