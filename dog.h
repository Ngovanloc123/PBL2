#pragma once
#include <raylib.h>
#include "animal.h"

class Dog : public Animal {
private:
    const char *purposeOfRaising;
    const char *levelOfTraining;
    const char *needForExercise;
    void DrawImageBorder1(const Font &myFon, int gridX = 0, int gridY = 0);
public:
    Dog(const char *name, const char *imagePet, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise);
    Dog(const Dog& dog);
    ~Dog();
    string GetType()  { return "Dog"; }
    void GetAndDisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);

    void displayInformation(const Font &myFont, Texture &texture);
};

