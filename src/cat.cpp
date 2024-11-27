#include "cat.h"
#include "color.h"
// #include <iostream>

using namespace std;

Cat::Cat(vector<string> inforNewCat)
{
    name = strdup(inforNewCat[0].c_str());
    imageAnimal = strdup(inforNewCat[1].c_str());
    origin = strdup(inforNewCat[2].c_str());
    averageAge = stoi(inforNewCat[3]);
    furType = strdup(inforNewCat[4].c_str());
    quantity = stoi(inforNewCat[5]);
    sellingPrice = stoi(inforNewCat[6]);
    size = stoi(inforNewCat[7]);
    coatColor = strdup(inforNewCat[8].c_str());
    popularity = strdup(inforNewCat[9].c_str());
    sheddingLevel = strdup(inforNewCat[10].c_str());
    appearance = strdup(inforNewCat[11].c_str());
}

Cat::Cat(const char *name, const char *imageCat, const char *originOfCat, unsigned int averageAge, const char *furType, unsigned int numberOfCat, unsigned int sellingPrice,
         unsigned int size, const char *coatColor, const char *popularity, const char *sheddingLevel, const char *appearance)
    : Animal(name, imageCat, originOfCat, averageAge, furType, numberOfCat, sellingPrice, size), coatColor(coatColor), popularity(popularity), sheddingLevel(sheddingLevel), appearance(appearance) {}

Cat::Cat(const Cat& cat) : Animal(cat), coatColor(cat.coatColor), popularity(cat.popularity), sheddingLevel(cat.sheddingLevel), appearance(cat.appearance) {}

Cat::~Cat() {}

vector<char *> Cat::getAttributes()
{
    return {(char*)coatColor, (char*)popularity, (char*)sheddingLevel, (char*)appearance, (char*)name};
}

vector<string> Cat::getAllAttributes()
{
    vector<string> result = Animal::getAllAttributes();
    result.push_back(coatColor);
    result.push_back(popularity);
    result.push_back(sheddingLevel);
    result.push_back(appearance);
    return result;
}

void Cat::DisplayImage(const Font &myFont, Texture &texture, int gridX, int gridY)
{
    // Nạp và chuyển đổi hình ảnh thành texture
    Image image = LoadImage(imageAnimal);
    if (image.width == 0 || image.height == 0)
    {
        imageAnimal = "image/Cats/default.png";
        image = LoadImage(imageAnimal);
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

void Cat::displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant)
{
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

    sprintf(fullText, "Coat Color: %s", coatColor);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 300}, 30, 2, darkGreen);

    sprintf(fullText, "Popularity: %s", popularity);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 330}, 30, 2, darkGreen);

    sprintf(fullText, "Shedding Level: %s", sheddingLevel);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 360}, 30, 2, darkGreen);
    
    sprintf(fullText, "Appearance: %s", appearance);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 390}, 30, 2, darkGreen);
    
    sprintf(fullText, "Max: %d", quantity);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150 + 248 + 150, 420}, 30, 2, darkGreen);

    if(quantity > 0) sprintf(fullText, "Status: In stock");
    else sprintf(fullText, "Status: Out of stock");
    DrawTextEx(myFont, fullText, (Vector2){(float)(informationFrame.x +  informationFrame.width / 2), 180}, 40, 2, darkGreen);

    // Chuyển số thành chuỗi
    sprintf(fullText, "%d", sellingPrice);

    // Thêm khoảng cách vào chuỗi giá tiền
    int len = strlen(fullText);
    int insertCount = 0;
    for (int i = len - 1; i > 0; --i) {
        if ((len - i) % 3 == 0) {
            for (int j = len + insertCount; j > i; --j) {
                fullText[j] = fullText[j - 1];
            }
            fullText[i] = ' ';
            insertCount++;
        }
    }
    fullText[len + insertCount] = '\0'; // Kết thúc chuỗi

    // Thêm " VND" vào cuối chuỗi
    strcat(fullText, " VND");

    // Vẽ khung thông tin giá tiền
    Rectangle frame = {(informationFrame.x + informationFrame.width / 2 + 40), 240, 220, 80};
    DrawRectangleRounded(frame, 0.6, 10, yellow);

    // Tính toán và canh giữa chuỗi trong khung
    Vector2 textSize = MeasureTextEx(myFont, fullText, 40, 2);
    float textX = frame.x + (frame.width - textSize.x) / 2;
    float textY = frame.y + (frame.height - textSize.y) / 2;

    // Vẽ chuỗi giá tiền
    DrawTextEx(myFont, fullText, (Vector2){textX, textY}, 40, 2, darkGreen);

    // Thêm vào giỏ hàng và mua hàng
    purchaseOptions(myFont, purQuant);
}
