#include "animal.h"

void Animal::ImageBorder(const Font &myFont, int posX, int posY)
{
    // Tạo khuông chứa hình ảnh
    int sizeImage = 240;
    if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)(posY), (float)sizeImage, (float)(sizeImage + 20)})) {
        // Viền khi không đưa chuột vào
        DrawRectangleLines(posX, posY , sizeImage, sizeImage + 20, BLACK);
    } else {
        // Viền khi đưa chuột vào
        DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)(sizeImage + 20)}, 0, 10, 5, Cardinal);
    }   
}

void Animal::ImageBorderInfor(const Font &myFont, int posX, int posY)
{
    int sizeImage = 240;
    DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)sizeImage}, 0, 10, 5, PINK); 
}

// bool Animal::addToCart(const Font &myFont, Rectangle &informationFrame)
// {
//     char fullText[100];
//     Rectangle frame;
//     sprintf(fullText, "Add to cart");
//     frame = {(float)(informationFrame.x + 100), 500, 200, 60};
//     DrawRectangleRounded(frame, 0.6, 10, GREEN);
//     DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);

//     if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
//         return true;
//     }
//     return false;
// }

// bool Animal::buyNow(const Font &myFont, Rectangle &informationFrame)
// {
//     char fullText[100];
//     Rectangle frame;
//     sprintf(fullText, "Buy now");
//     frame = {(float)(informationFrame.x + informationFrame.width / 2 + 100), 500, 200, 60};
//     DrawRectangleRounded(frame, 0.6, 10, RED);
//     DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);

//     if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
//         return true;
//     }
//     return false;
// }

void Animal::purchaseOptions(const Font &myFont, Rectangle &informationFrame)
{
    char fullText[100];
    Rectangle frame;
    // Nút thêm vào giỏ hàng, mua hàng
    if(quantity > 0) {
        // addToCart(myFont, informationFrame);
        sprintf(fullText, "Add to cart");
        frame = {(float)(informationFrame.x + 100), 500, 200, 60};
        DrawRectangleRounded(frame, 0.6, 10, GREEN);
        DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);

        // buyNow(myFont, informationFrame);
        sprintf(fullText, "Buy now");
        frame = {(float)(informationFrame.x + informationFrame.width / 2 + 100), 500, 200, 60};
        DrawRectangleRounded(frame, 0.6, 10, RED);
        DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);
    }
    else {
        sprintf(fullText, "ITPet will update you as soon as possible");
        DrawTextEx(myFont, fullText, (Vector2){informationFrame.x + 20, 540}, 30, 2, BLACK);
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

bool Animal::isAddToCart()
{
    Rectangle frame =  {(float)((float)(248 + 8 + 100 + 100)), 500, 200, 60};
    if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        return true;
    }
    return false;
}

bool Animal::isBuyNow()
{
    Rectangle frame = {(float)((float)(248 + 8 + 100 + 240 * 3 / 2 + 100)), 500, 200, 60};
    if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        return true;
    }
    return false;
}

void Animal::DisplayImage(const Font &myFont, Texture &texture, int gridX, int gridY)
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

    // Tên hình ảnh
    Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
    DrawRectangleRounded(nameFrame, 0, 10, WHITE);
    // Vẽ tên hình ảnh
    DrawTextEx(myFont, name, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, name, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
    
    // Tạo khuông chứa hình ảnh
    ImageBorder(myFont, posX, posY);
}

void Animal::ImageInfor(const Font &myFont, Texture &texture, int gridX, int gridY)
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

    // // Tên hình ảnh
    // Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
    // DrawRectangleRounded(nameFrame, 0, 10, WHITE);
    // // Vẽ tên hình ảnh
    // DrawTextEx(myFont, name, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, name, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
    
    // Tạo khuông chứa hình ảnh
    ImageBorderInfor(myFont, posX, posY);
}
