#pragma once
#include<iostream>
#include <raylib.h>

using namespace std;
class Animal {
    protected:
        const char *name;
        const char *imageAnimal;
        const char *origin; 
        unsigned int averageAge;
        const char *furType;
        unsigned int quantity;
        unsigned int sellingPrice;
        unsigned int size;
    public:
        Animal();
        Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size);
        Animal(const Animal& Animal);
        ~Animal();
        const char *getName() const;
        void displayInformation(const Font &myFont, Texture &texture) {}
};

