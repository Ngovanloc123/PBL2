#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <dogLibrary.h>
#include <catLibrary.h>
#include <color.h>

using namespace std;

const int widthWindow =  1200;
const int heightWindow = 720;

typedef enum Screens {
    MENU = 0,
    informationDog,
    informationCat,
    detail
} Screens;

int main() {
    // Increate Window
    cout << "Open My shop..." << endl;
    InitWindow(widthWindow, heightWindow, "Shop Pet");

    // Set FPS
    SetTargetFPS(60);

    // Load Texture
    Image image = LoadImage("image/background.png");
    Texture textureMenu = LoadTextureFromImage(image);
    UnloadImage(image);

    Dogs dogs;
    Cats cats;
    // Tải phông chữ tùy chỉnh
    Font myFont = LoadFont("font/NerkoOne-Regular.ttf");

    Screens currentScreen = MENU;

    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(PINK);
        // Background
        int posX = (widthWindow - textureMenu.width) / 2;
        int posY = (heightWindow - textureMenu.height) / 2;
        DrawTexture(textureMenu, posX, posY, WHITE);

        // Màn hình MENU
        if(currentScreen == MENU) {
            DrawTextEx(myFont, "WELCOME", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "WELCOME", 60, 2).x / 2), 100}, 60, 2, darkGreen);
            DrawTextEx(myFont, "TO", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "TO", 50, 2).x / 2), 170}, 50, 2, darkGreen);
            DrawTextEx(myFont, "SHOP PET", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "SHOP PET", 80, 2).x / 2), 210}, 80, 2, darkGreen);

            Rectangle buttonDog = {(widthWindow) / 2 - 100, (heightWindow) / 2, 200, 50};
            DrawRectangleRounded(buttonDog, 0.6, 10, yellow);
            DrawTextEx(myFont, "Cho canh", (Vector2){buttonDog.x + buttonDog.width / 2 - MeasureTextEx(myFont, "Cho canh", 30, 2).x / 2, buttonDog.y + 10}, 30, 2, darkGreen);

            Rectangle buttonCat = {(widthWindow) / 2 - 100, (heightWindow) / 2 + 100, 200, 50};
            DrawRectangleRounded(buttonCat, 0.6, 10, yellow);
            DrawTextEx(myFont, "Meo canh", (Vector2){buttonCat.x + buttonCat.width / 2 - MeasureTextEx(myFont, "Meo canh", 30, 2).x / 2, buttonCat.y + 10}, 30, 2, darkGreen);

            if(CheckCollisionPointRec(GetMousePosition(), buttonDog) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                currentScreen = informationDog;
            }

            if(CheckCollisionPointRec(GetMousePosition(), buttonCat) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                currentScreen = informationCat;
            }
        }
        // Màn hình lựa chọn chó
        if(currentScreen == informationDog) {
            // Các thông tin
            DrawTextEx(myFont, "Cho Canh", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Cho Canh", 60, 2).x / 2), 50}, 60, 2, darkGreen);
            // Hình ảnh chó
            dogs.DrawDogs(myFont);

            // Back
            Rectangle buttonBack = {10, 10, 50, 50};
            DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
            DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

            if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = MENU;
            }

        }

        // Màn hình lựa chọn mèo
        if(currentScreen == informationCat) {
            // Các thông tin
            DrawTextEx(myFont, "INFORMATION", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "INFORMATION", 60, 2).x / 2), 50}, 60, 2, darkGreen);
            // Hình ảnh Mèo
            cats.DrawAbyssiniand();
            cats.DrawBengal();
            cats.DrawBirman();

            // Back
            Rectangle buttonBack = {10, 10, 50, 50};
            DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
            DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

            if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = MENU;
            }

        }

        if (currentScreen == detail) {
            // Thông tin
        }
        EndDrawing();
    }
    UnloadTexture(textureMenu);
    UnloadFont(myFont);
    CloseWindow();
    return 0;
}
