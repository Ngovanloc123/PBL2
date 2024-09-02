#pragma once
#include <raylib.h>

typedef enum Screens {
    MENU = 0,
    informationDog,
    informationCat,
    detail
} Screens;

class Screen {
private:
    const int widthWindow =  1200;
    const int heightWindow = 720;
    Texture textureMenu;
public:
    Screens currentScreen = MENU;

public:
    Screen()
    {
        textureMenu = {0};
        InitWindow(widthWindow, heightWindow, "Shop Pet");
        // Set FPS
        SetTargetFPS(60);
        // Load Texture
        Image image = LoadImage("image/background.png");
        textureMenu = LoadTextureFromImage(image);
        UnloadImage(image);
    }
     ~Screen()
    {
        if (textureMenu.id != 0)
        {
            UnloadTexture(textureMenu);
        }
    }
    void backGround();
    void DrawMenu(Font myFont);
    void DrawDogInfoScreen(Font myFont);
    void DrawCatInfoScreen(Font myFont);
};