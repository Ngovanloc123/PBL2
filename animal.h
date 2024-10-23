#pragma once
#include<iostream>
#include <raylib.h>
#include "color.h"

using namespace std;
class Animal {
    protected:
        const char *name;
        const char *imageAnimal;    // Link hình ảnh
        const char *origin;         // Nguồn gốc        
        unsigned int averageAge;    // Tuổi trung bình
        const char *furType;        // Kiểu lông
        unsigned int quantity;      // Số lượng
        unsigned int sellingPrice;  // Giá bán
        unsigned int size;          // Kích thước
    void DrawImageBorder(const Font &myFont, int gridX = 0, int gridY = 0);
    // void DrawImageBorder2(const Font &myFont, int gridX = 0, int gridY = 0);
    public:
        Animal();
        Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size);
        Animal(const Animal& Animal);
        ~Animal();
        const char *getName() const;
        void displayInformation(const Font &myFont, Texture &texture) {}
};

