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
    void ImageBorder(const Font &myFont, int posX = 108, int posY = 136);
    void ImageBorderInfor(const Font &myFont, int posX = 108, int posY = 136);
    // void addToCart(const Font &myFont, Rectangle &informationFrame);
    // void buyNow(const Font &myFont, Rectangle &informationFrame);
    void purchaseOptions(const Font &myFont, Rectangle &informationFrame);
    public:
        Animal();
        Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size);
        Animal(const Animal& Animal);
        ~Animal();
        const char *getName() const;
        bool isAddToCart();
        bool isBuyNow();
        void DisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
        void ImageInfor(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
        void displayInformation(const Font &myFont, Texture &texture) {}
};