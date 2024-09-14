#include"pet.h"


Pet::Pet() {}

Pet::Pet(string name, string origin, unsigned int averageAge, string furType, unsigned int number, unsigned int sellingPrice, unsigned int size) 
    : name(name), origin(origin), averageAge(averageAge), furType(furType), number(number), sellingPrice(sellingPrice), size(size) {}
Pet::Pet(const Pet& pet) {
    name = pet.name;
    origin = pet.origin;
    averageAge = pet.averageAge;
    furType = pet.furType;
    number = pet.number;
    sellingPrice = pet.sellingPrice;
    size = pet.size;
}
Pet::~Pet() {}

string Pet::getName()
{
    return name;
}

void Pet::displayInformation()
{
    cout << "Name: " << name << endl;
    cout << "Origin: " << origin << endl;
    cout << "Average Age: " << averageAge << endl;
    cout << "Fur Type: " << furType << endl;
    cout << "Number: " << number << endl;
    cout << "Selling Price: " << sellingPrice << endl;
    cout << "Size: " << size << endl;
    cout << "\n";
}