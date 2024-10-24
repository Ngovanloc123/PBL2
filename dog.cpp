#include "dog.h"
#include <color.h>
// #include <iostream>

using namespace std;

Dog::Dog(const char *name, const char *imageDog, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise)
    : Animal(name, imageDog, originOfDog, averageAge, furType, numberOfDog, sellingPrice, size), purposeOfRaising(purposeOfRaising), levelOfTraining(levelOfTraining), needForExercise(needForExercise) {}

Dog::Dog(const Dog& dog) : Animal(dog), purposeOfRaising(dog.purposeOfRaising), levelOfTraining(dog.levelOfTraining), needForExercise(dog.needForExercise) {}

Dog::~Dog() {}


void Dog::displayInformation(const Font &myFont, Texture &texture) {
    GetAndDisplayImage(myFont, texture);
    DrawImageBorder(myFont);

    // Khung chứa thông tin
    Rectangle informationFrame = {(float)(248 + 8 + 100), (float)(128), 240 * 3, 240 * 2};
    DrawRectangleRounded(informationFrame, 0.2, 10, WHITE);
    // Vẽ thông tin
    char fullText[100];
    sprintf(fullText, "Name: %s", name);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 150}, 35, 2, darkGreen);
    sprintf(fullText, "Origin: %s", origin);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 180}, 30, 2, darkGreen);
    sprintf(fullText, "Average Age: %d", averageAge);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 210}, 30, 2, darkGreen);
    sprintf(fullText, "Fur Type: %s", furType);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 240}, 30, 2, darkGreen);
    sprintf(fullText, "Quantity: %d", quantity);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 270}, 30, 2, darkGreen);
    sprintf(fullText, "Selling Price: %d", sellingPrice);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 300}, 30, 2, darkGreen);
    sprintf(fullText, "Size: %d", size);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 330}, 30, 2, darkGreen);
    sprintf(fullText, "Purpose of Raising: %s", purposeOfRaising);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 360}, 30, 2, darkGreen);
    sprintf(fullText, "Level of Training: %s", levelOfTraining);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 390}, 30, 2, darkGreen);
    sprintf(fullText, "Need for Exercise: %s", needForExercise);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 420}, 30, 2, darkGreen);

}

void Dog::GetAndDisplayImage(const Font &myFont, Texture &texture, int gridX, int gridY)
{
    // Nạp và chuyển đổi hình ảnh thành texture
    Image image = LoadImage(imageAnimal);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    // Vị trí ảnh
    int posX = gridX * 248 + 8 + 100;
    int posY = gridY * 270 + 128 + 8;
    // Vẽ hình ảnh
    DrawTexture(texture, posX, posY, WHITE);
    
    // Tạo khuông chứa hình ảnh
    DrawImageBorder(myFont, gridX, gridY);
}
