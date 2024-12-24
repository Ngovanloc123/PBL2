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
#include "animalDetal.h"


using namespace std;


class FileManager {
public:
    static vector<Customer*> loadCustomerFromFile(const string& filename);
    static vector<AnimalDetail*> loadAnimalDetailFromFile(const string& filename);
    static void saveToFile(const string& filename, const vector<Customer*>& customer);

    static void saveToFileDog(const string& filename, LinkedList<Dog> dogList);
    static void saveToFileCat(const string& filename, LinkedList<Cat> catList);
    static void saveToFileAnimalDetail(const string& filename, vector<AnimalDetail*>& animalDetail);
};
