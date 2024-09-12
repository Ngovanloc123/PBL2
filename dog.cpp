#include "dog.h"
#include <color.h>
#include <iostream>

using namespace std;

void Dogs::LoadAndDrawInfor(Font myFont, const char *nameDog, const char *filePath, int gridX, int gridY) {
    // Nạp ảnh và chuyển đổi ảnh thành texture 
    Image image = LoadImage(filePath);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    textureDog = LoadTextureFromImage(image);
    UnloadImage(image);
    // Vị trí ảnh
    int posX = gridX * 248 + 8 + 100;
    int posY = gridY * 270 + 128 + 8;
    int sizeImage = 240;
    // Vẽ hình ảnh
    DrawTexture(textureDog, posX, posY, WHITE);
    // Vẽ tên hình ảnh
    Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
    DrawRectangleRounded(nameFrame, 0, 10, WHITE);
    DrawTextEx(myFont, nameDog, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, nameDog, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
    // Vẽ viền
    if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)posY, (float)sizeImage, (float)sizeImage})) {
        DrawRectangleLines(posX, posY , sizeImage, sizeImage + 20, BLACK);
    } else {
        // Viền khi đưa chuột vào
        DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)(sizeImage + 20)}, 0, 10, 5, Cardinal);
    }
    
}

void Dogs::DrawPape1(Font myFont)
{
    LoadAndDrawInfor(myFont, "Afghan Hound", "image/Dogs/Afghan-Hound.png", 0, 0); 
    LoadAndDrawInfor(myFont, "Akita", "image/Dogs/Akita.png", 1, 0); 
    LoadAndDrawInfor(myFont, "Alabai", "image/Dogs/Alabai.png", 2, 0);
    LoadAndDrawInfor(myFont, "Alaska", "image/Dogs/Alaska.png", 3, 0); 
    LoadAndDrawInfor(myFont, "American Bully", "image/Dogs/American-Bully.png", 0, 1); 
    LoadAndDrawInfor(myFont, "Australian Shepherd", "image/Dogs/Australian-Shepherd.png", 1, 1); 
    LoadAndDrawInfor(myFont, "Bac Ha", "image/Dogs/Bac-Ha.png", 2, 1); 
    LoadAndDrawInfor(myFont, "Bac Kinh", "image/Dogs/Bac-Kinh.png", 3, 1); 
}

void Dogs::DrawPape2(Font myFont)
{
    LoadAndDrawInfor(myFont, "Basenji", "image/Dogs/Basenji.png", 0, 0); 
    LoadAndDrawInfor(myFont, "Basset Hound", "image/Dogs/Basset-Hound.png", 1, 0); 
    LoadAndDrawInfor(myFont, "Beagle", "image/Dogs/Beagle.png", 2, 0); 
    LoadAndDrawInfor(myFont, "Becgie Duc", "image/Dogs/Becgie-Duc.png", 3, 0); 
    LoadAndDrawInfor(myFont, "Becgie Ha Lan", "image/Dogs/Becgie-Ha-Lan.png", 0, 1); 
    LoadAndDrawInfor(myFont, "Bichon", "image/Dogs/Bichon.png", 1, 1); 
    LoadAndDrawInfor(myFont, "Border Collie", "image/Dogs/Border-Collie.png", 2, 1); 
    LoadAndDrawInfor(myFont, "Boston Terrier", "image/Dogs/Boston-Terrier.png", 3, 1); 
}

void Dogs::DrawPape3(Font myFont)
{
    LoadAndDrawInfor(myFont, "Boxer", "image/Dogs/Boxer.png", 0, 0); 
    LoadAndDrawInfor(myFont, "Bull Anh", "image/Dogs/Bull-Anh.png", 1, 0); 
    LoadAndDrawInfor(myFont, "Bull Phap", "image/Dogs/Bull-Phap.png", 2, 0); 
    LoadAndDrawInfor(myFont, "Bull Terrier", "image/Dogs/Bull-Terrier.png", 3, 0); 
    LoadAndDrawInfor(myFont, "Caucasian Shepherd", "image/Dogs/Caucasian-Shepherd.png", 0, 1); 
    LoadAndDrawInfor(myFont, "Cavalier King Charles", "image/Dogs/Cavalier-King-Charles-Spaniel.png", 1, 1); 
    LoadAndDrawInfor(myFont, "Chihuahua", "image/Dogs/Chihuahua.png", 2, 1); 
    LoadAndDrawInfor(myFont, "Chinese Crested", "image/Dogs/Chinese-Crested.png", 3, 1);
}

void Dogs::DrawPape4(Font myFont)
{
    LoadAndDrawInfor(myFont, "Chow Chow", "image/Dogs/Chow-Chow.png", 0, 0);
    LoadAndDrawInfor(myFont, "Cocker Spaniel", "image/Dogs/Cocker-Spaniel.png", 1, 0);
    LoadAndDrawInfor(myFont, "Dalmatian", "image/Dogs/Dalmatian.png", 2, 0);
    LoadAndDrawInfor(myFont, "Doberman", "image/Dogs/Doberman.png", 3, 0);
    LoadAndDrawInfor(myFont, "German Pinscher", "image/Dogs/German-Pinscher.png", 0, 1);
    LoadAndDrawInfor(myFont, "Golden Retriever", "image/Dogs/Golden-Retriever.png", 1, 1);
    LoadAndDrawInfor(myFont, "Great Dane", "image/Dogs/Great-Dane.png", 2, 1); 
    LoadAndDrawInfor(myFont, "Pembroke Corgi", "image/Dogs/Pembroke-Welsh-Corgi.png", 3, 1); 
}

void Dogs::DrawDogs(Font myFont)
{
    // Nút trở lại trang trước
    Rectangle backPage = {20, 400, 40, 40};
    if(page != 1) {
        DrawRectangleRounded(backPage, 0.6, 10, yellow);
        DrawTextEx(myFont, "<<", (Vector2){backPage.x + backPage.width / 2 - MeasureTextEx(myFont, "<<", 30, 2).x / 2, backPage.y + 10}, 30, 2, darkGreen);
    }
    // Nút trang tiếp theo
    Rectangle nextPage = {1200 - 20 - MeasureTextEx(myFont, ">>", 30, 2).x, 400, 40, 40};
    if(page != 4) {
        DrawRectangleRounded(nextPage, 0.6, 10, yellow);
        DrawTextEx(myFont, ">>", (Vector2){nextPage.x + nextPage.width / 2 - MeasureTextEx(myFont, ">>", 30, 2).x / 2, nextPage.y + 10}, 30, 2, darkGreen);
    }
    // Xữ lý nút back
    if(CheckCollisionPointRec(GetMousePosition(), backPage) && page != 1) {
        DrawRectangleRoundedLines((Rectangle){backPage.x , backPage.y, backPage.height, backPage.width}, 0.6, 10, 5, Cardinal);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            page--;
        } 
    }
    // Xữ lý nút next
    if(CheckCollisionPointRec(GetMousePosition(), nextPage) && page!= 4) {
        DrawRectangleRoundedLines((Rectangle){nextPage.x , nextPage.y, nextPage.height, nextPage.width}, 0.6, 10, 5, Cardinal);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            page++;
        }
    }
    // Chuyển trang
    switch (page)
    {
    case 1:
        DrawPape1(myFont);
        break;
    case 2:
        DrawPape2(myFont);
        break;
    case 3:
        DrawPape3(myFont);
        break;
    case 4:
        DrawPape4(myFont);
        break;
    default:
        break;
    }
}
// ----------------------------------------------------------------
// Dog::Dog() {}
Dogs::Dogs(string name, string originOfDog, unsigned int averageAge, string furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, string purposeOfRaising, string levelOfTraining, string needForExercise)
    : Pet(name, originOfDog, averageAge, furType, numberOfDog, sellingPrice, size), purposeOfRaising(purposeOfRaising), levelOfTraining(levelOfTraining), needForExercise(needForExercise) {}
Dogs::Dogs(const Dogs& dog) : Pet(dog), purposeOfRaising(dog.purposeOfRaising), levelOfTraining(dog.levelOfTraining), needForExercise(dog.needForExercise) {}
// Dog::~Dog() {}
void Dogs::displayInformation() {
    Pet::displayInformation();
    cout << "Purpose of Raising: " << purposeOfRaising << endl;
    cout << "Level of Training: " << levelOfTraining << endl;
    cout << "Need for Exercise: " << needForExercise << endl;
}
