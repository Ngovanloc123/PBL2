#pragma once
#include <raylib.h>
#include "animal.h"
#include "LinkedList.h"

class Dog : public Animal {
private:
    const char *purposeOfRaising;   // Mục đích nuôi
    const char *levelOfTraining;    // Mức độ huấn luyện
    const char *needForExercise;    // Nhu cầu hoạt động
public:
    Dog(const char *name, const char *imagePet, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise);
    Dog(const Dog& dog);
    ~Dog();
    string GetType()  { return "Dog"; }
    static void initializePetList(LinkedList<Dog>& dogList) {
        Dog dog("Akita", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog);
        Dog dog2("B", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog2);
        Dog dog3("U", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog3);
        Dog dog4("R", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog4);
        Dog dog5("M", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog5);
        Dog dog6("E", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog6);
        Dog dog7("H", "image/Dogs/Basenji.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
        dogList.insert(dog7);
    }
    void GetAndDisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
    void displayInformation(const Font &myFont, Texture &texture);
};

