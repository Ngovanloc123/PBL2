#include "dogLibrary.h"
#include <iostream>

using namespace std;

Color Cardinal = Color{196, 30, 58, 255};

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
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                DrawRectangleLines(posX + i, posY + j, width, height, Cardinal);
            }
        }
    }
}

void Dogs::DrawDog(const char* imagePath, int gridX, int gridY) {
    int posX = gridX * 248 + 8;
    int posY = gridY * 248 + 128 + 8;
    int width = 240;
    int height = 240;

    LoadAndDrawInfor(imagePath, posX, posY, width, height);
}

void Dogs::DrawAfghanHound() { DrawDog("image/Dogs/Afghan-Hound.png", 0, 0); }
void Dogs::DrawAkita() { DrawDog("image/Dogs/Akita.png", 1, 0); }
void Dogs::DrawAlabai() { DrawDog("image/Dogs/Alabai.png", 2, 0); }
void Dogs::DrawAlaska() { DrawDog("image/Dogs/Alaska.png", 3, 0); }
void Dogs::DrawAmericanBully() { DrawDog("image/Dogs/American-Bully.png", 0, 1); }
void Dogs::DrawAustralianShepherd() { DrawDog("image/Dogs/Australian-Shepherd.png", 1, 1); }
void Dogs::DrawBacHa() { DrawDog("image/Dogs/Bac-Ha.png", 2, 1); }
void Dogs::DrawBacKinh() { DrawDog("image/Dogs/Bac-Kinh.png", 3, 1); }

void Dogs::DrawBasenji() { DrawDog("image/Dogs/Basenji.png", 0, 0); }
void Dogs::DrawBassetHound() { DrawDog("image/Dogs/Basset-Hound.png", 1, 0); }
void Dogs::DrawBeagle() { DrawDog("image/Dogs/Beagle.png", 2, 0); }
void Dogs::DrawBecgieDuc() { DrawDog("image/Dogs/Becgie-Duc.png", 3, 0); }
void Dogs::DrawBecgieHaLan() { DrawDog("image/Dogs/Becgie-Ha-Lan.png", 0, 1); }
void Dogs::DrawBichon() { DrawDog("image/Dogs/Bichon.png", 1, 1); }
void Dogs::DrawBorderCollie() { DrawDog("image/Dogs/Border-Collie.png", 2, 1); }
void Dogs::DrawBostonTerrier() { DrawDog("image/Dogs/Boston-Terrier.png", 3, 1); }

void Dogs::DrawBostonBoxer() { DrawDog("image/Dogs/Boxer.png", 0, 0); }
void Dogs::DrawBullAnh() { DrawDog("image/Dogs/Bull-Anh.png", 1, 0); }
void Dogs::DrawBullPhap() { DrawDog("image/Dogs/Bull-Phap.png", 2, 0); }
void Dogs::DrawBullTerrier() { DrawDog("image/Dogs/Bull-Terrier.png", 3, 0); }
void Dogs::DrawCaucasianShepherd() { DrawDog("image/Dogs/Caucasian-Shepherd.png", 0, 1); }
void Dogs::DrawCavalierKingCharlesSpaniel() { DrawDog("image/Dogs/Cavalier-King-Charles-Spaniel.png", 1, 1); }
void Dogs::DrawChihuahua() { DrawDog("image/Dogs/Chihuahua.png", 2, 1); }
void Dogs::DrawChineseCrested() { DrawDog("image/Dogs/Chinese-Crested.png", 3, 1); }

void Dogs::DrawChowChow() { DrawDog("image/Dogs/Chow-Chow.png", 0, 0); }
void Dogs::DrawCockerSpaniel() { DrawDog("image/Dogs/Cocker-Spaniel.png", 1, 0); }
void Dogs::DrawDalmatian() { DrawDog("image/Dogs/Dalmatian.png", 2, 0); }
void Dogs::DrawDoberman() { DrawDog("image/Dogs/Doberman.png", 3, 0); }
void Dogs::DrawGermanPinscher() { DrawDog("image/Dogs/German-Pinscher.png", 0, 1); }
void Dogs::DrawGoldenRetriever() { DrawDog("image/Dogs/Golden-Retriever.png", 1, 1); }
void Dogs::DrawGreatDane() { DrawDog("image/Dogs/Great-Dane.png", 2, 1); }
void Dogs::DrawPembrokeWelshCorgi() { DrawDog("image/Dogs/Pembroke-Welsh-Corgi.png", 3, 1); }

void Dogs::DrawPape1()
{
    DrawAfghanHound();
    DrawAkita();
    DrawAlabai();
    DrawAlaska();
    DrawAmericanBully();
    DrawAustralianShepherd();
    DrawBacHa();
    DrawBacKinh();
}

void Dogs::DrawPape2()
{
    DrawBasenji();
    DrawBassetHound();
    DrawBeagle();
    DrawBecgieDuc();
    DrawBecgieHaLan();
    DrawBichon();
    DrawBorderCollie();
    DrawBostonTerrier();
}

void Dogs::DrawPape3()
{
    DrawBostonBoxer();
    DrawBullAnh();
    DrawBullPhap();
    DrawBullTerrier();
    DrawCaucasianShepherd();
    DrawCavalierKingCharlesSpaniel();
    DrawChihuahua();
    DrawChineseCrested();
}

void Dogs::DrawPape4()
{
    DrawChowChow();
    DrawCockerSpaniel();
    DrawDalmatian();
    DrawDoberman();
    DrawGermanPinscher();
    DrawGoldenRetriever();
    DrawGreatDane();
    DrawPembrokeWelshCorgi();
}
