#include "screen.h"
#include <color.h>

void Screen::backGround()
{
    int posX = (widthWindow - textureMenu.width) / 2;
    int posY = (heightWindow - textureMenu.height) / 2;
    DrawTexture(textureMenu, posX, posY, WHITE);
}

void Screen::DrawMenu(Font myFont)
{
    DrawTextEx(myFont, "WELCOME", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "WELCOME", 60, 2).x / 2), 100}, 60, 2, darkGreen);
    DrawTextEx(myFont, "TO", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "TO", 50, 2).x / 2), 170}, 50, 2, darkGreen);
    DrawTextEx(myFont, "SHOP PET", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "SHOP PET", 80, 2).x / 2), 210}, 80, 2, darkGreen);

    Rectangle buttonDog = {(float)((widthWindow) / 2 - 100), (float)((heightWindow) / 2), 200, 50};
    DrawRectangleRounded(buttonDog, 0.6, 10, yellow);
    DrawTextEx(myFont, "Cho canh", (Vector2){buttonDog.x + buttonDog.width / 2 - MeasureTextEx(myFont, "Cho canh", 30, 2).x / 2, buttonDog.y + 10}, 30, 2, darkGreen);

    Rectangle buttonCat = {(float)((widthWindow) / 2 - 100), (float)((heightWindow) / 2 + 100), 200, 50};
    DrawRectangleRounded(buttonCat, 0.6, 10, yellow);
    DrawTextEx(myFont, "Meo canh", (Vector2){buttonCat.x + buttonCat.width / 2 - MeasureTextEx(myFont, "Meo canh", 30, 2).x / 2, buttonCat.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), buttonDog) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        currentScreen = informationDog;
    }

    if(CheckCollisionPointRec(GetMousePosition(), buttonCat) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        currentScreen = informationCat;
    }
}

void Screen::DrawDogInfoScreen(Font myFont)
{
    DrawTextEx(myFont, "Cho Canh", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Cho Canh", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    // Back
    Rectangle buttonBack = {10, 10, 50, 50};
    DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
    DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = MENU;
    }
}

void Screen::DrawCatInfoScreen(Font myFont)
{
    DrawTextEx(myFont, "Meo Canh", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Meo Canh", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    // Back
    Rectangle buttonBack = {10, 10, 50, 50};
    DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
    DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = MENU;
    }
}
