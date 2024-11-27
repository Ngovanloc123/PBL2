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

void Animal::purchaseOptions(const Font &myFont, unsigned int &purQuant)
{
    char fullText[100];
    Rectangle informationFrame = {(float)(248 + 8 + 100), (float)(128), 240 * 3, 240 * 2};
    Rectangle frame;
    // Nút thêm vào giỏ hàng, mua hàng
    if(quantity > 0) {
        // addToCart(myFont, informationFrame);
        sprintf(fullText, "Add to cart");
        frame = {(float)(informationFrame.x + 100), 500, 200, 60};
        DrawRectangleRounded(frame, 0.6, 10, GREEN);
        DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);


        // Tăng giảm số lượng mua
        Rectangle Decrease = {(informationFrame.x + informationFrame.width / 2 + 40), 360, 50, 40};
        DrawRectangleRounded(Decrease, 0, 10, yellow);
        DrawTextEx(myFont, "-", (Vector2){Decrease.x + Decrease.width / 2 - MeasureTextEx(myFont, "-", 40, 2).x / 2, Decrease.y + Decrease.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);

        Rectangle Increase = {(informationFrame.x + informationFrame.width / 2 + 40 + 50 +50), 360, 50, 40};
        DrawRectangleRounded(Increase, 0, 10, yellow);
        DrawTextEx(myFont, "+", (Vector2){Increase.x + Increase.width / 2 - MeasureTextEx(myFont, "+", 40, 2).x / 2, Increase.y + Increase.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);

        sprintf(fullText, "%d", purQuant);
        Rectangle quan = {(informationFrame.x + informationFrame.width / 2 + 40 + 50), 360, 50, 40};
        DrawRectangleRoundedLines(quan, 0, 10, 0, BLACK);
        DrawTextEx(myFont, fullText, (Vector2){quan.x + quan.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, quan.y + quan.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, BLACK);

        // xử lý nút tăng giảm
        if(CheckCollisionPointRec(GetMousePosition(), Increase) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if(purQuant < quantity) {
                purQuant++;
            }
        }
        if(CheckCollisionPointRec(GetMousePosition(), Decrease) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if(purQuant > 1) {
                purQuant--;
            }
        }
    }
    else {
        sprintf(fullText, "ITPet will update you as soon as possible");
        DrawTextEx(myFont, fullText, (Vector2){informationFrame.x + 20, 540}, 30, 2, BLACK);
    }
    // Delete
        sprintf(fullText, "Delete");
        frame = {(float)(informationFrame.x + 550), 500, 150, 60};
        DrawRectangleRounded(frame, 0.6, 10, RED);
        DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);
    // Update
        sprintf(fullText, "Update");
        frame = {(float)(informationFrame.x + 350), 500, 150, 60};
        DrawRectangleRounded(frame, 0.6, 10, BLUE);
        DrawTextEx(myFont, fullText, (Vector2){frame.x + frame.width / 2 - MeasureTextEx(myFont, fullText, 40, 2).x / 2, frame.y + frame.height / 2 - MeasureTextEx(myFont, fullText, 40, 2).y / 2}, 40, 2, WHITE);
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

const char *Animal::getImageAnimal() const
{
    return imageAnimal;
}

const char *Animal::getOrigin() const
{
    return origin;
}

unsigned int Animal::getAverageAge() const
{
    return averageAge;
}

const char *Animal::getFurType() const
{
    return furType;
}

unsigned int Animal::getQuantity() const
{
    return quantity;
}

unsigned int Animal::getPrice() const
{
    return sellingPrice;
}

unsigned int Animal::getSize() const
{
    return size;
}

void Animal::setQuantity(unsigned int quantity)
{
    this->quantity = quantity;
    cout << "Quantity: " << quantity << endl;
    cout << "Name: " << name << endl;
}

unsigned int Animal::getSellingPrice() const
{
    return sellingPrice;
}

vector<string> Animal::getAllAttributes()
{
    vector<string> attributes;
    attributes.push_back(name);
    attributes.push_back(imageAnimal);
    attributes.push_back(origin);
    attributes.push_back(to_string(averageAge));
    attributes.push_back(furType);
    attributes.push_back(to_string(quantity));
    attributes.push_back(to_string(sellingPrice));
    attributes.push_back(to_string(size));
    return attributes;
}

// bool Animal::isAddToCart()
// {
//     Rectangle frame =  {(float)((float)(248 + 8 + 100 + 100)), 500, 200, 60};
//     if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
//         // Xử lý ở đây về số lượng mua
//         return true;
//     }
//     return false;
// }

bool Animal::isBuyNow()
{
    Rectangle frame = {(float)((float)(248 + 8 + 100 + 240 * 3 / 2 + 100)), 500, 200, 60};
    if(CheckCollisionPointRec(GetMousePosition(), frame) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        return true;
    }
    return false;
}

// void Animal::DisplayImage(const Font &myFont, Texture &texture, int gridX, int gridY)
// {
//     // Nạp và chuyển đổi hình ảnh thành texture
//     Image image = LoadImage(imageAnimal);
//     if (image.width == 0 || image.height == 0)
//     {
//         cout << "Failed to load image!" << endl;
//         return;
//     }
//     texture = LoadTextureFromImage(image);
//     UnloadImage(image);
//     // Vị trí ảnh
//     int posX = gridX * 248 + 8 + 100;
//     int posY = gridY * 270 + 128 + 8;
//     // Vẽ hình ảnh
//     DrawTexture(texture, posX, posY, WHITE);

//     // Tên hình ảnh
//     Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
//     DrawRectangleRounded(nameFrame, 0, 10, WHITE);
//     // Vẽ tên hình ảnh
//     DrawTextEx(myFont, name, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, name, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
    
//     // Tạo khuông chứa hình ảnh
//     ImageBorder(myFont, posX, posY);
// }

void Animal::DisplayItemFromCart(const Font &myFont, Texture &texture, int gridX, int gridY, unsigned int purQuant)
{
    // Nạp và chuyển đổi hình ảnh thành texture
    Image imageA = LoadImage(imageAnimal);
    if (imageA.width == 0 || imageA.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    ImageResize(&imageA, 140, 140);
    texture = LoadTextureFromImage(imageA);

    // Vị trí ảnh
    float posX = gridX * (500 + 30) + 100;
    float posY = gridY * (imageA.width + 5) + 128;
    // Vẽ hình ảnh
    DrawTexture(texture, posX, posY, WHITE);
    
    // Tạo khuông chứa hình ảnh
    // ImageBorderInfor(myFont, posX, posY);

    // Tạo khuông chứa thông tin
    Rectangle informationFrame = {(float)(posX + imageA.width), (float)(posY), 360, (float)imageA.height};
    DrawRectangleRounded(informationFrame, 0.2, 10, WHITE);
    DrawRectangleRoundedLines(informationFrame, 0.2, 10, 5, PINK);

    // In thông tin cần thiết về tên và giá bên cạnh hình ảnh
    char fullText[100];
    DrawTextEx(myFont, name, (Vector2){posX + imageA.width + 10, posY}, 30, 2, darkGreen);
    sprintf(fullText, "%d VND", sellingPrice);
    DrawTextEx(myFont, fullText, (Vector2){posX + imageA.width + 10, posY + 40}, 30, 2, darkGreen);
    // In số lượng trong giỏ hàng
    sprintf(fullText, "Quantity: %d", purQuant);
    DrawTextEx(myFont, fullText, (Vector2){posX + imageA.width + 10, posY + 80}, 30, 2, darkGreen);
    // In thùng rác
    Image imageCart = LoadImage("./image/bin.png");
    if (imageCart.width == 0 || imageCart.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    ImageResize(&imageCart, 40, 40);
    texture = LoadTextureFromImage(imageCart);
    DrawTexture(texture, posX + 300 + imageA.width, posY + imageA.height/2 - imageCart.height/2, WHITE);


    UnloadImage(imageCart);
    UnloadImage(imageA);

}

void Animal::DisplayImageInInfor(const Font &myFont, Texture &texture, int gridX, int gridY)
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

    ImageBorderInfor(myFont, posX, posY);
}
