#include "catLibrary.h"
#include <iostream>

using namespace std;

void Cats::LoadAndDrawInfor(const char *filePath, int posX, int posY, int width, int height) {
    Image image = LoadImage(filePath);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    textureMap = LoadTextureFromImage(image);
    UnloadImage(image);
    DrawTexture(textureMap, posX, posY, WHITE);
    DrawRectangleLines(posX, posY, width, height, BLACK); 
    
}

void Cats::DrawAbyssiniand() { LoadAndDrawInfor("image/Cats/Abyssinian.png", 0*128 + 4, 1*128 + 4, 120, 120); }

void Cats::DrawBengal() { LoadAndDrawInfor("image/Cats/Bengal.png", 1*128 + 4, 1*128 + 4, 120, 120); }

void Cats::DrawBirman() { LoadAndDrawInfor("image/Cats/Birman.png", 2*128 + 4, 1*128 + 4, 120, 120); }
