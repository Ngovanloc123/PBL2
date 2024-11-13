#pragma once
#include <raylib.h>
#include <string>
#include "LinkedList.cpp"
#include "dog.h"
#include "color.h"



typedef enum Screens {
    HOME = 0,
    imagesDog,
    imagesCat,
    detailDog,
    detailCat,
    INTRO,
    CONTACT,
    shoppingCart
} Screens;

class Screen {
private:
    const int widthWindow =  1200;
    const int heightWindow = 720;
    Texture textureMenu;

    void backButton(const Font &myFont);
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

    Image loadImageCart();
public:
    Screens beforeScreen = HOME;
    Screens currentScreen = HOME;

public:
    Screen();
     ~Screen()
    {
        if (textureMenu.id != 0)
        {
            UnloadTexture(textureMenu);
        }
    }
    void backGround();

    void DrawHome(const Font &myFont);
    // void DrawIntro(const Font &myFont);
    // void DrawContact(const Font &myFont);

    void navigationMenu(const Font &myFont, Texture &textureCart);

    template <typename T>
    void DrawHeadingAnimal(const Font &myFont, LinkedList<T> &list) {
        if(currentScreen == imagesDog)
        DrawTextEx(myFont, "Dog", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Dog", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        if(currentScreen == imagesCat)
            DrawTextEx(myFont, "Cat", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Cat", 60, 2).x / 2), 50}, 60, 2, darkGreen);
        // Button
        backButton(myFont);
        previousButton(myFont,list);
        nextButton(myFont,list);
    }
    template <typename T>
void getNode(LinkedList<T> &list, Node<T>* &NodeAnimal) {
    // Kiểm tra nếu chuột được nhấn
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 index = GetMousePosition();

        // Xác định node phù hợp dựa trên màn hình hiện tại
        if (currentScreen == imagesDog || currentScreen == imagesCat) {
            NodeAnimal = list.GetNodeFromAnimal(index);
        } else if (currentScreen == shoppingCart) {
            NodeAnimal = list.GetNodeFromCart(index);
        } else {
            NodeAnimal = NULL;
        }

        // Nếu NodeAnimal hợp lệ, kiểm tra loại đối tượng
        if (NodeAnimal != NULL) {
            string type = NodeAnimal->getData().GetType();

            // Chuyển màn hình dựa trên loại động vật
            if (type == "Dog") {
                beforeScreen = currentScreen;
                currentScreen = detailDog;
            } else if (type == "Cat") {
                beforeScreen = currentScreen;
                currentScreen = detailCat;
            }
        }
    }
}



    template <typename T>
    void deleteNode(LinkedList<T> &list) {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 index = GetMousePosition();
            list.deleteNodeFromCart(index);
        }
    }
    void Heading(const Font &myFont);
};