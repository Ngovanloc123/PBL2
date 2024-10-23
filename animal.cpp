#include "animal.h"

void Animal::DrawImageBorder(const Font &myFont, int gridX, int gridY)
{
    // Tạo khuông chứa hình ảnh
        int sizeImage = 240;
        // Vị trí khung
        int posX = gridX * 248 + 8 + 100;
        int posY = gridY * 270 + 128 + 8;
        Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
        DrawRectangleRounded(nameFrame, 0, 10, WHITE);
        // Vẽ tên hình ảnh
        DrawTextEx(myFont, name, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, name, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
        // Vẽ viền khi đưa chuột và không đưa chuột
        if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)(posY), (float)sizeImage, (float)(sizeImage + 20)})) {
            // Viền khi không đưa chuột vào
            DrawRectangleLines(posX, posY , sizeImage, sizeImage + 20, BLACK);
        } else {
            // Viền khi đưa chuột vào
            DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)(sizeImage + 20)}, 0, 10, 5, Cardinal);
        }   
}

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