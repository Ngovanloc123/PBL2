#include "dog.h"
#include "color.h"
// #include <iostream>

using namespace std;


Dog::Dog(vector<string> inforNewDog)
{
    name = strdup(inforNewDog[0].c_str());
    imageAnimal = strdup(inforNewDog[1].c_str());
    origin = strdup(inforNewDog[2].c_str());
    averageAge = stoi(inforNewDog[3]);
    furType = strdup(inforNewDog[4].c_str());
    quantity = stoi(inforNewDog[5]);
    sellingPrice = stoi(inforNewDog[6]);
    size = stoi(inforNewDog[7]);
    purposeOfRaising = strdup(inforNewDog[8].c_str());
    levelOfTraining = strdup(inforNewDog[9].c_str());
    needForExercise = strdup(inforNewDog[10].c_str());
}


Dog::Dog(const char *name, const char *imageDog, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise)
    : Animal(name, imageDog, originOfDog, averageAge, furType, numberOfDog, sellingPrice, size), purposeOfRaising(purposeOfRaising), levelOfTraining(levelOfTraining), needForExercise(needForExercise) {}

Dog::Dog(const Dog& dog) : Animal(dog), purposeOfRaising(dog.purposeOfRaising), levelOfTraining(dog.levelOfTraining), needForExercise(dog.needForExercise) {}

Dog::~Dog() {}

const char *Dog::getPurposeOfRaising() const
{
    return purposeOfRaising;
}

const char *Dog::getLevelOfTraining() const
{
    return levelOfTraining;
}

const char *Dog::getNeedForExercise() const
{
    return needForExercise;
}

vector<char *> Dog::getAttributes()
{
    vector<char*> details;
    details.push_back((char*)purposeOfRaising); // Convert to char* and add to vector
    details.push_back((char*)levelOfTraining); // Same here
    details.push_back((char*)needForExercise); // Same here
    details.push_back(nullptr); // Add nullptr as a char* instead of a null terminator
    details.push_back((char*)name); // Convert name to char* and add to vector
    return details;
}

vector<string> Dog::getAllAttributes()
{
    vector<string> attributes = Animal::getAllAttributes();
    attributes.push_back(purposeOfRaising);
    attributes.push_back(levelOfTraining);
    attributes.push_back(needForExercise);
    return attributes;
}

void Dog::DisplayImage(const Font &myFont, Texture &texture, int gridX, int gridY)
{
    // Nạp và chuyển đổi hình ảnh thành texture
    Image image = LoadImage(imageAnimal);
    if (image.width == 0 || image.height == 0)
    {
        imageAnimal = "image/Dogs/default.png";
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

void Dog::displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant)
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

    sprintf(fullText, "Purpose of Raising: %s", purposeOfRaising);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 300}, 30, 2, darkGreen);

    sprintf(fullText, "Level of Training: %s", levelOfTraining);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 330}, 30, 2, darkGreen);

    sprintf(fullText, "Need for Exercise: %s", needForExercise);
    DrawTextEx(myFont, fullText, (Vector2){248 + 150, 360}, 30, 2, darkGreen);

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

    // Số lượng mua

    // Mua hàng
    purchaseOptions(myFont, purQuant);
}
