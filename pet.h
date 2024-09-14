#pragma once
#include<string>
#include<iostream>

using namespace std;
class Pet {
    private:
        string name;
        string origin; 
        unsigned int averageAge;
        string furType;
        unsigned int number;
        unsigned int sellingPrice;
        unsigned int size;
    public:
        Pet();
        Pet(string name, string origin, unsigned int averageAge, string furType, unsigned int number, unsigned int sellingPrice, unsigned int size);
        Pet(const Pet& pet);
        ~Pet();
        string getName();
        void displayInformation();
};

