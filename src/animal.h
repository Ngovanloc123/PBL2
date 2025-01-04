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

        // Hiệu ứng border khi đưa con trỏ vào hình ảnh
        void ImageBorder(const Font &myFont, int posX = 108, int posY = 136);

        // Border hình ảnh khi hiển thị thông tin chi tiết
        void ImageBorderInfor(const Font &myFont, int posX = 108, int posY = 136);

        // Các tùy chọn khi mua hàng
        void purchaseOptions(const Font &myFont, unsigned int &purQuant);
    public:
        //----------------------------------------------------------------
        // Constructor và destructor
        Animal();
        Animal(const char *name, const char *imageAnimal, const char *origin, unsigned int averageAge, const char *furType, unsigned int quantity, unsigned int sellingPrice, unsigned int size);
        Animal(const Animal& Animal);
        virtual ~Animal();

        
        virtual string GetType() const { return "Animal"; }
        // In ra thông tin chi tiết
        virtual void displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant) = 0;

        //----------------------------------------------------------------
        // Hàm lấy thông tin
        const char *getName() const;
        const char *getImageAnimal() const;
        const char *getOrigin() const;
        unsigned int getAverageAge() const;
        const char *getFurType() const;
        unsigned int getQuantity() const;
        unsigned int getPrice() const;
        unsigned int getSize() const;
        unsigned int getSellingPrice() const;
        vector<string> getAllAttributes();

        //----------------------------------------------------------------
        // Hàm cập nhật thông tin
        void setQuantity(unsigned int quantity);
        
        bool isBuyNow();
        // In ra hình ảnh và thông tin cần thiết trong giỏ hàng
        void DisplayItemFromCart(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0, unsigned int purQuant = 1);
        // In ra hình ảnh tại thông tin chi tiết
        void DisplayImageInInfor(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
};