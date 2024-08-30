#include "dogLibrary.h"
#include <iostream>

using namespace std;


void Dogs::LoadAndDrawInfor(const char *filePath, int posX, int posY, int width, int height) {
    Image image = LoadImage(filePath);
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        return;
    }
    textureDog = LoadTextureFromImage(image);
    UnloadImage(image);
    DrawTexture(textureDog, posX, posY, WHITE);
    if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)posY, (float)width, (float)height})) {
        DrawRectangleLines(posX, posY, width, height, BLACK); 
    } else {
        DrawRectangleLines(posX, posY, width, height, RED);
    }
}


void Dogs::DrawAfghanHound() { LoadAndDrawInfor("image/Dogs/Afghan-Hound.png", 0*248 + 8, 0* 248 + 128 + 8, 240, 240); }
void Dogs::DrawAkita() { LoadAndDrawInfor("image/Dogs/Akita.png", 1*248 + 8, 0*248 + 128 + 8, 240, 240); }
void Dogs::DrawAlabai() { LoadAndDrawInfor("image/Dogs/Alabai.png", 2*248 + 8, 0*248 + 128 + 8, 240, 240); }
void Dogs::DrawAlaska() { LoadAndDrawInfor("image/Dogs/Alaska.png", 3*248 + 8, 0*248 + 128 + 8, 240, 240); }
// void Dogs::DrawAmericanBully() { LoadAndDrawInfor("image/Dogs/American-Bully.png", 4*128 + 8, 1*128 + 8, 120, 120); }
// void Dogs::DrawAustralianShepherd() { LoadAndDrawInfor("image/Dogs/Australian-Shepherd.png", 5*128 + 8, 1*128 + 8, 120, 120); }
// void Dogs::DrawBacHa() { LoadAndDrawInfor("image/Dogs/Bac-Ha.png", 6*128 + 8, 1*128 + 8, 120, 120); }
// void Dogs::DrawBacKinh() { LoadAndDrawInfor("image/Dogs/Bac-Kinh.png", 7*128 + 8, 1*128 + 8, 120, 120); }

// void Dogs::DrawBasenji() { LoadAndDrawInfor("image/Dogs/Basenji.png", 0*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBassetHound() { LoadAndDrawInfor("image/Dogs/Basset-Hound.png", 1*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBeagle() { LoadAndDrawInfor("image/Dogs/Beagle.png", 2*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBecgieDuc() { LoadAndDrawInfor("image/Dogs/Becgie-Duc.png", 3*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBecgieHaLan() { LoadAndDrawInfor("image/Dogs/Becgie-Ha-Lan.png", 4*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBichon() { LoadAndDrawInfor("image/Dogs/Bichon.png", 5*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBorderCollie() { LoadAndDrawInfor("image/Dogs/Border-Collie.png", 6*128 + 8, 2*128 + 8, 120, 120); }
// void Dogs::DrawBostonTerrier() { LoadAndDrawInfor("image/Dogs/Boston-Terrier.png", 7*128 + 8, 2*128 + 8, 120, 120); }

// void Dogs::DrawBullAnh() { LoadAndDrawInfor("image/Dogs/Bull-Anh.png", 0*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawBullTerrier() { LoadAndDrawInfor("image/Dogs/Bull-Terrier.png", 1*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawCaucasianShepherd() { LoadAndDrawInfor("image/Dogs/Caucasian-Shepherd.png", 2*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawCavalierKingCharlesSpaniel() { LoadAndDrawInfor("image/Dogs/Cavalier-King-Charles-Spaniel.png", 19*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawChihuahua() { LoadAndDrawInfor("image/Dogs/Chihuahua.png", 3*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawChineseCrested() { LoadAndDrawInfor("image/Dogs/Chinese-Crested.png", 4*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawChowChow() { LoadAndDrawInfor("image/Dogs/Chow-Chow.png", 5*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawCockerSpaniel() { LoadAndDrawInfor("image/Dogs/Cocker-Spaniel.png", 6*128 + 8, 3*128 + 8, 120, 120); }
// void Dogs::DrawDalmatian() { LoadAndDrawInfor("image/Dogs/Dalmatian.png", 7*128 + 8, 3*128 + 8, 120, 120); }

// void Dogs::DrawDoberman() { LoadAndDrawInfor("image/Dogs/Doberman.png", 0*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawGermanPinscher() { LoadAndDrawInfor("image/Dogs/German-Pinscher.png", 1*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawGoldenRetriever() { LoadAndDrawInfor("image/Dogs/Golden-Retriever.png", 2*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawGreatDane() { LoadAndDrawInfor("image/Dogs/Great-Dane.png", 3*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawHmong() { LoadAndDrawInfor("image/Dogs/Hmong.png", 4*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawHusky() { LoadAndDrawInfor("image/Dogs/Husky.png", 5*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawIcelandicSheepdog() { LoadAndDrawInfor("image/Dogs/Icelandic-Sheepdog.png", 6*128 + 8, 4*128 + 8, 120, 120); }
// void Dogs::DrawIrishSetter() { LoadAndDrawInfor("image/Dogs/Irish-Setter.png", 7*128 + 8, 4*128 + 8, 120, 120); }
