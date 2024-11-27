#pragma once
#include<iostream>
#include <raylib.h>
#include <vector>

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

        // Khung hình ảnh khi đưa ra bán
        void ImageBorder(const Font &myFont, int posX = 108, int posY = 136);
        // Khung hình ảnh khi hiển thị thông tin chi tiết
        void ImageBorderInfor(const Font &myFont, int posX = 108, int posY = 136);
        // void addToCart(const Font &myFont, Rectangle &informationFrame);
        // void buyNow(const Font &myFont, Rectangle &informationFrame);
        void purchaseOptions(const Font &myFont, unsigned int &purQuant);
    public:
        Animal();
        Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size);
        Animal(const Animal& Animal);
        virtual ~Animal();
        const char *getName() const;
        unsigned int getQuantity() const;
        unsigned int getSellingPrice() const;
        vector<string> getAllAttributes();
        virtual string GetType() const { return "Animal"; }
        // bool isAddToCart();
        bool isBuyNow();
        // In ra hình ảnh khi bán
        virtual void DisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0) = 0;
        // In ra hình ảnh và thông tin cần thiết trong giỏ hàng
        void DisplayItemFromCart(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0, unsigned int purQuant = 1);
        // In ra hình ảnh tại thông tin chi tiết
        void DisplayImageInInfor(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
        // In ra thông tin chi tiết
        virtual void displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant) = 0;
};