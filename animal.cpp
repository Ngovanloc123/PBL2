#include "animal.h"


Animal::Animal() {}

Animal::Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size) 
    : name(name), imageAnimal(imageAnimal), origin(origin), averageAge(averageAge), furType(furType), quantity(quantity), sellingPrice(sellingPrice), size(size) {}
Animal::Animal(const Animal& Animal) {
    name = Animal.name;
    imageAnimal = Animal.imageAnimal;
    origin = Animal.origin;
    averageAge = Animal.averageAge;
    furType = Animal.furType;
    quantity = Animal.quantity;
    sellingPrice = Animal.sellingPrice;
    size = Animal.size;
}
Animal::~Animal() {}

const char *Animal::getName() const
{
    return name;
}

// const char *Animal::getName() const
// {
//     return name;
// }

// void Animal::displayInformation()
// {
//     cout << "Name: " << name << endl;
//     cout << "Origin: " << origin << endl;
//     cout << "Average Age: " << averageAge << endl;
//     cout << "Fur Type: " << furType << endl;
//     cout << "Quantity: " << quantity << endl;
//     cout << "Selling Price: " << sellingPrice << endl;
//     cout << "Size: " << size << endl;
// }