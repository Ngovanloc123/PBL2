#include "dogLibrary.h"
#include <color.h>
#include <iostream>

using namespace std;

Color Cardinal = Color{196, 30, 58, 255};

void Dogs::LoadAndDrawInfor(const char *filePath, int gridX, int gridY) {
    Image image = LoadImage(filePath);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    textureDog = LoadTextureFromImage(image);
    UnloadImage(image);

    int posX = gridX * 248 + 8 + 100;
    int posY = gridY * 270 + 128 + 8;
    int sizeImage = 240;
    DrawTexture(textureDog, posX, posY, WHITE);
    if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)posY, (float)sizeImage, (float)sizeImage})) {
        DrawRectangleLines(posX, posY, sizeImage, sizeImage, BLACK); 
    } else {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                DrawRectangleLines(posX + i, posY + j, sizeImage, sizeImage, Cardinal);
            }
        }
    }
}

void Dogs::DrawPape1()
{
    LoadAndDrawInfor("image/Dogs/Afghan-Hound.png", 0, 0); 
    LoadAndDrawInfor("image/Dogs/Akita.png", 1, 0); 
    LoadAndDrawInfor("image/Dogs/Alabai.png", 2, 0);
    LoadAndDrawInfor("image/Dogs/Alaska.png", 3, 0); 
    LoadAndDrawInfor("image/Dogs/American-Bully.png", 0, 1); 
    LoadAndDrawInfor("image/Dogs/Australian-Shepherd.png", 1, 1); 
    LoadAndDrawInfor("image/Dogs/Bac-Ha.png", 2, 1); 
    LoadAndDrawInfor("image/Dogs/Bac-Kinh.png", 3, 1); 
}

void Dogs::DrawPape2()
{
    LoadAndDrawInfor("image/Dogs/Basenji.png", 0, 0); 
    LoadAndDrawInfor("image/Dogs/Basset-Hound.png", 1, 0); 
    LoadAndDrawInfor("image/Dogs/Beagle.png", 2, 0); 
    LoadAndDrawInfor("image/Dogs/Becgie-Duc.png", 3, 0); 
    LoadAndDrawInfor("image/Dogs/Becgie-Ha-Lan.png", 0, 1); 
    LoadAndDrawInfor("image/Dogs/Bichon.png", 1, 1); 
    LoadAndDrawInfor("image/Dogs/Border-Collie.png", 2, 1); 
    LoadAndDrawInfor("image/Dogs/Boston-Terrier.png", 3, 1); 
}

void Dogs::DrawPape3()
{
    LoadAndDrawInfor("image/Dogs/Boxer.png", 0, 0); 
    LoadAndDrawInfor("image/Dogs/Bull-Anh.png", 1, 0); 
    LoadAndDrawInfor("image/Dogs/Bull-Phap.png", 2, 0); 
    LoadAndDrawInfor("image/Dogs/Bull-Terrier.png", 3, 0); 
    LoadAndDrawInfor("image/Dogs/Caucasian-Shepherd.png", 0, 1); 
    LoadAndDrawInfor("image/Dogs/Cavalier-King-Charles-Spaniel.png", 1, 1); 
    LoadAndDrawInfor("image/Dogs/Chihuahua.png", 2, 1); 
    LoadAndDrawInfor("image/Dogs/Chinese-Crested.png", 3, 1);
}

void Dogs::DrawPape4()
{
    LoadAndDrawInfor("image/Dogs/Chow-Chow.png", 0, 0);
    LoadAndDrawInfor("image/Dogs/Cocker-Spaniel.png", 1, 0); 
    LoadAndDrawInfor("image/Dogs/Dalmatian.png", 2, 0); 
    LoadAndDrawInfor("image/Dogs/Doberman.png", 3, 0); 
    LoadAndDrawInfor("image/Dogs/German-Pinscher.png", 0, 1); 
    LoadAndDrawInfor("image/Dogs/Golden-Retriever.png", 1, 1); 
    LoadAndDrawInfor("image/Dogs/Great-Dane.png", 2, 1); 
    LoadAndDrawInfor("image/Dogs/Pembroke-Welsh-Corgi.png", 3, 1); 
}

void Dogs::DrawDogs(Font myFont)
{
    Rectangle backPage = {20, 400, 40, 40};
    DrawRectangleRounded(backPage, 0.6, 10, yellow);
    DrawTextEx(myFont, "<<", (Vector2){backPage.x + backPage.width / 2 - MeasureTextEx(myFont, "<<", 30, 2).x / 2, backPage.y + 10}, 30, 2, darkGreen);

    Rectangle nextPage = {1200 - 20 - MeasureTextEx(myFont, ">>", 30, 2).x, 400, 40, 40};
    DrawRectangleRounded(nextPage, 0.6, 10, yellow);
    DrawTextEx(myFont, ">>", (Vector2){nextPage.x + nextPage.width / 2 - MeasureTextEx(myFont, ">>", 30, 2).x / 2, nextPage.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), backPage) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(page != 1) page--;
    }
    if(CheckCollisionPointRec(GetMousePosition(), nextPage) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(page!= 4) page++;
    }
    switch (page)
    {
    case 1:
        DrawPape1();
        break;
    case 2:
        DrawPape2();
        break;
    case 3:
        DrawPape3();
        break;
    case 4:
        DrawPape4();
        break;
    default:
        break;
    }
}

