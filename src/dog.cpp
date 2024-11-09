#include "dog.h"
#include "color.h"
// #include <iostream>

using namespace std;

Dog::Dog(const char *name, const char *imageDog, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise)
    : Animal(name, imageDog, originOfDog, averageAge, furType, numberOfDog, sellingPrice, size), purposeOfRaising(purposeOfRaising), levelOfTraining(levelOfTraining), needForExercise(needForExercise) {}

Dog::Dog(const Dog& dog) : Animal(dog), purposeOfRaising(dog.purposeOfRaising), levelOfTraining(dog.levelOfTraining), needForExercise(dog.needForExercise) {}

Dog::~Dog() {}


void Dog::displayInformation(const Font &myFont, Texture &texture) {
    DisplayImageInInfor(myFont, texture);

    // Khung chứa thông tin
    Rectangle informationFrame = {(float)(248 + 8 + 100), (float)(128), 240 * 3, 240 * 2};
    DrawRectangleRounded(informationFrame, 0.2, 10, WHITE);
    DrawRectangleRoundedLines(informationFrame, 0.2, 10, 5, PINK);
    // Vẽ thông tin
    char fullText[100];
    sprintf(fullText, name);
    DrawTextEx(myFont, fullText, (Vector2){(float)(informationFrame.x +  informationFrame.width / 2 - MeasureTextEx(myFont, fullText, 60, 2).x / 2), informationFrame.y}, 60, 2, darkGreen);

    sprintf(fullText, "Origin: %s", origin);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 180}, 30, 2, darkGreen);

    sprintf(fullText, "Average Age: %d", averageAge);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 210}, 30, 2, darkGreen);

    sprintf(fullText, "Fur Type: %s", furType);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 240}, 30, 2, darkGreen);

    if(size == 1)  strcpy(fullText, "Size: Small");
    if(size == 2)  strcpy(fullText, "Size: Medium");
    if(size == 3)  strcpy(fullText, "Size: Large");
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 270}, 30, 2, darkGreen);

    sprintf(fullText, "Purpose of Raising: %s", purposeOfRaising);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 300}, 30, 2, darkGreen);

    sprintf(fullText, "Level of Training: %s", levelOfTraining);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 330}, 30, 2, darkGreen);

    sprintf(fullText, "Need for Exercise: %s", needForExercise);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 360}, 30, 2, darkGreen);

    if(quantity > 0) sprintf(fullText, "Status: In stock");
    else sprintf(fullText, "Status: Out of stock");
    DrawTextEx(myFont, fullText, (Vector2){(float)(informationFrame.x +  informationFrame.width / 2), 180}, 40, 2, darkGreen);

    sprintf(fullText, "%d", sellingPrice);
    Rectangle frame = {(informationFrame.x + informationFrame.width / 2 + 40), 240, 150, 80};
    DrawRectangleRounded(frame, 0.6, 10, yellow);
    // Tính toán độ rộng của chuỗi fullText
    Vector2 textSize = MeasureTextEx(myFont, fullText, 40, 2);
    // Canh giữa chuỗi fullText trong hình chữ nhật
    float textX = frame.x + (frame.width - textSize.x) / 2;
    float textY = frame.y + (frame.height - textSize.y) / 2;
    // Vẽ chuỗi text ra màn hình
    DrawTextEx(myFont, fullText, (Vector2){textX, textY}, 40, 2, darkGreen);

    // Số lượng mua

    // Thêm vào giỏ hàng và mua hàng
    purchaseOptions(myFont, informationFrame);
}
