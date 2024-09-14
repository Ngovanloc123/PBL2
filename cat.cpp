#include "cat.h"
#include <color.h>
#include <iostream>

using namespace std;


void Cats::LoadAndDrawInfor(Font myFont, const char *nameCat, const char *filePath, int gridX, int gridY) {
    // Nạp ảnh và chuyển đổi ảnh thành texture 
    Image image = LoadImage(filePath);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    textureCat = LoadTextureFromImage(image);
    UnloadImage(image);
    // Vị trí ảnh
    int posX = gridX * 248 + 8 + 100;
    int posY = gridY * 270 + 128 + 8;
    int sizeImage = 240;
    // Vẽ hình ảnh
    DrawTexture(textureCat, posX, posY, WHITE);
    // Vẽ tên hình ảnh
    Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
    DrawRectangleRounded(nameFrame, 0, 10, WHITE);
    DrawTextEx(myFont, nameCat, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, nameCat, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
    // Vẽ viền
    if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)posY, (float)sizeImage, (float)sizeImage})) {
        DrawRectangleLines(posX, posY , sizeImage, sizeImage + 20, BLACK);
    } else {
        // Viền khi đưa chuột vào
        DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)(sizeImage + 20)}, 0, 10, 5, Cardinal);
    }
    
}

void Cats::DrawPape1(Font myFont)
{
    // LoadAndDrawInfor(myFont, "Afghan Hound", "image/Cats/Afghan-Hound.png", 0, 0); 
    // LoadAndDrawInfor(myFont, "Akita", "image/Cats/Akita.png", 1, 0); 
    // LoadAndDrawInfor(myFont, "Alabai", "image/Cats/Alabai.png", 2, 0);
    // LoadAndDrawInfor(myFont, "Alaska", "image/Cats/Alaska.png", 3, 0); 
    // LoadAndDrawInfor(myFont, "American Bully", "image/Cats/American-Bully.png", 0, 1); 
    // LoadAndDrawInfor(myFont, "Australian Shepherd", "image/Cats/Australian-Shepherd.png", 1, 1); 
    // LoadAndDrawInfor(myFont, "Bac Ha", "image/Cats/Bac-Ha.png", 2, 1); 
    // LoadAndDrawInfor(myFont, "Bac Kinh", "image/Cats/Bac-Kinh.png", 3, 1); 
}

void Cats::DrawPape2(Font myFont)
{
    // LoadAndDrawInfor(myFont, "Basenji", "image/Cats/Basenji.png", 0, 0); 
    // LoadAndDrawInfor(myFont, "Basset Hound", "image/Cats/Basset-Hound.png", 1, 0); 
    // LoadAndDrawInfor(myFont, "Beagle", "image/Cats/Beagle.png", 2, 0); 
    // LoadAndDrawInfor(myFont, "Becgie Duc", "image/Cats/Becgie-Duc.png", 3, 0); 
    // LoadAndDrawInfor(myFont, "Becgie Ha Lan", "image/Cats/Becgie-Ha-Lan.png", 0, 1); 
    // LoadAndDrawInfor(myFont, "Bichon", "image/Cats/Bichon.png", 1, 1); 
    // LoadAndDrawInfor(myFont, "Border Collie", "image/Cats/Border-Collie.png", 2, 1); 
    // LoadAndDrawInfor(myFont, "Boston Terrier", "image/Cats/Boston-Terrier.png", 3, 1); 
}

void Cats::DrawPape3(Font myFont)
{
    // LoadAndDrawInfor(myFont, "Boxer", "image/Cats/Boxer.png", 0, 0); 
    // LoadAndDrawInfor(myFont, "Bull Anh", "image/Cats/Bull-Anh.png", 1, 0); 
    // LoadAndDrawInfor(myFont, "Bull Phap", "image/Cats/Bull-Phap.png", 2, 0); 
    // LoadAndDrawInfor(myFont, "Bull Terrier", "image/Cats/Bull-Terrier.png", 3, 0); 
    // LoadAndDrawInfor(myFont, "Caucasian Shepherd", "image/Cats/Caucasian-Shepherd.png", 0, 1); 
    // LoadAndDrawInfor(myFont, "Cavalier King Charles", "image/Cats/Cavalier-King-Charles-Spaniel.png", 1, 1); 
    // LoadAndDrawInfor(myFont, "Chihuahua", "image/Cats/Chihuahua.png", 2, 1); 
    // LoadAndDrawInfor(myFont, "Chinese Crested", "image/Cats/Chinese-Crested.png", 3, 1);
}

void Cats::DrawPape4(Font myFont)
{
//     LoadAndDrawInfor(myFont, "Chow Chow", "image/Cats/Chow-Chow.png", 0, 0);
//     LoadAndDrawInfor(myFont, "Cocker Spaniel", "image/Cats/Cocker-Spaniel.png", 1, 0);
//     LoadAndDrawInfor(myFont, "Dalmatian", "image/Cats/Dalmatian.png", 2, 0);
//     LoadAndDrawInfor(myFont, "Doberman", "image/Cats/Doberman.png", 3, 0);
//     LoadAndDrawInfor(myFont, "German Pinscher", "image/Cats/German-Pinscher.png", 0, 1);
//     LoadAndDrawInfor(myFont, "Golden Retriever", "image/Cats/Golden-Retriever.png", 1, 1);
//     LoadAndDrawInfor(myFont, "Great Dane", "image/Cats/Great-Dane.png", 2, 1); 
//     LoadAndDrawInfor(myFont, "Pembroke Corgi", "image/Cats/Pembroke-Welsh-Corgi.png", 3, 1); 
}

void Cats::DrawCats(Font myFont)
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
// Cats::Cats() {}
Cats::Cats(string name, string originOfCat, unsigned int averageAge, string furType, unsigned int numberOfCat, unsigned int sellingPrice, unsigned int size, string specialCharacter, string coatColor, string hairLossLevel, string appearance)
    : Pet(name, originOfCat, averageAge, furType, numberOfCat, sellingPrice, size), specialCharacter(specialCharacter), coatColor(coatColor), hairLossLevel(hairLossLevel), appearance(appearance) {}
Cats::Cats(const Cats& cat) : Pet(cat), specialCharacter(cat.specialCharacter), coatColor(cat.coatColor), hairLossLevel(cat.hairLossLevel), appearance(cat.appearance) {}
// Cats::~Cats() {}
void Cats::displayInformation() {
    Pet::displayInformation();
    cout << "Special Character: " << specialCharacter << endl;
    cout << "Coat Color: " << coatColor << endl;
    cout << "Hair Loss Level: " << hairLossLevel << endl;
    cout << "Appearance: " << appearance << endl;
}
