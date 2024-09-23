#pragma once
#include <raylib.h>
#include <string>
#include "LinkedList.cpp"
#include "dog.h"
#include "color.h"



typedef enum Screens {
    MENU = 0,
    imagesDog,
    imagesCat,
    detailDog,
    detailCat
} Screens;

class Screen {
private:
    const int widthWindow =  1200;
    const int heightWindow = 720;
    Texture textureMenu;

    void backButton(const Font &myFont) {
        // Back
        Rectangle buttonBack = {10, 10, 50, 50};
        DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
        DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

        if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if(currentScreen == detailDog) currentScreen = (Screens)(currentScreen - 2);
            else
            if(currentScreen == detailCat) currentScreen = (Screens)(currentScreen - 2);
            else
            if(currentScreen == imagesDog) currentScreen = (Screens)(currentScreen - 1);
            else
            if(currentScreen == imagesCat) currentScreen = (Screens)(currentScreen - 2);
        }
    }
    template <typename T>
    void nextButton(const Font &myFont, LinkedList<T> &list) {
        // Nút trang tiếp theo
        Rectangle nextPage = {1200 - 20 - MeasureTextEx(myFont, ">>", 30, 2).x, 400, 40, 40};
        if(list.getPage() != list.getPageMax()) {
            DrawRectangleRounded(nextPage, 0.6, 10, yellow);
            DrawTextEx(myFont, ">>", (Vector2){nextPage.x + nextPage.width / 2 - MeasureTextEx(myFont, ">>", 30, 2).x / 2, nextPage.y + 10}, 30, 2, darkGreen);
        }
        // Xữ lý nút next
        if(CheckCollisionPointRec(GetMousePosition(), nextPage) && list.getPage() != list.getPageMax()) {
            DrawRectangleRoundedLines((Rectangle){nextPage.x , nextPage.y, nextPage.height, nextPage.width}, 0.6, 10, 5, Cardinal);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                list.setPage(list.getPage() + 1);
            }
        }
    }

    template <typename T>
    void previousButton(const Font &myFont, LinkedList<T> &list) {
        // Nút trở lại trang trước
        Rectangle previousPage = {20, 400, 40, 40};
        if(list.getPage() != 1) {
            DrawRectangleRounded(previousPage, 0.6, 10, yellow);
            DrawTextEx(myFont, "<<", (Vector2){previousPage.x + previousPage.width / 2 - MeasureTextEx(myFont, "<<", 30, 2).x / 2, previousPage.y + 10}, 30, 2, darkGreen);
        }
        // Xữ lý nút previous
        if(CheckCollisionPointRec(GetMousePosition(), previousPage) && list.getPage() != 1) {
            DrawRectangleRoundedLines((Rectangle){previousPage.x , previousPage.y, previousPage.height, previousPage.width}, 0.6, 10, 5, Cardinal);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                list.setPage(list.getPage() - 1);
            } 
        }
    }
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
    void backGround() {
        int posX = (widthWindow - textureMenu.width) / 2;
        int posY = (heightWindow - textureMenu.height) / 2;
        DrawTexture(textureMenu, posX, posY, WHITE);
    }

    void DrawMenu(Font myFont) {
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
            currentScreen = imagesDog;
        }

        if(CheckCollisionPointRec(GetMousePosition(), buttonCat) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            currentScreen = imagesCat;
        }
    }

    template <typename T>
    void DrawText_DrawTextLabel_Image(const Font &myFont, LinkedList<T> &list) {
        if(currentScreen == imagesDog)
        DrawTextEx(myFont, "Cho Canh", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Cho Canh", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        if(currentScreen == imagesCat)
            DrawTextEx(myFont, "Meo Canh", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Meo Canh", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        // // Back
        backButton(myFont);
        previousButton(myFont,list);
        nextButton(myFont,list);
    }
    template <typename T>
    void HandleMouseClick(LinkedList<T> &list, Node<T>* &NodeAnimal) {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 index = GetMousePosition();
            NodeAnimal = list.GetNodeFromClick(index);
            if(NodeAnimal != NULL) {
                // Kiểm tra nếu NodeAnimal chứa dữ liệu là Dog
                string type = NodeAnimal->getData().GetType();
                if (type == "Dog") {
                    currentScreen = detailDog; // Đối tượng là Dog
                } else if (type == "Cat") {
                    currentScreen = detailCat; // Đối tượng là Cat
                }
            }
        }
    }

    void DrawText_DrawTextLabel_Detail(const Font &myFont) {
        if(currentScreen == detailDog)
        DrawTextEx(myFont, "detailDog", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "detailDog", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        if(currentScreen == detailCat)
            DrawTextEx(myFont, "detailCat", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "detailCat", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        // // Back
        backButton(myFont);
    }
};