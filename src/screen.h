#pragma once
#include <raylib.h>
#include <string>
#include "LinkedList.cpp"
#include "customer.h"
#include "dog.h"
#include "color.h"
#include "statistical.h"



typedef enum Screens {
    HOME = 0,
    imagesDog,
    imagesCat,
    detailDog,
    detailCat,
    INTRO,
    CART,
    HISTORY
} Screens;

class Screen {
private:
    const int widthWindow =  1200;
    const int heightWindow = 720;
    Texture textureMenu;

    bool login;

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
    void DrawInputBox(const Font &font, string &inputText, int boxX, int boxY, int boxWidth, int boxHeight, int maxChars);
    // Kiểm tra cac nút liên quan đến đăng nhập
    // bool checkLoginButton(const Font &myFont);
    
    Image loadImageCart();
public:
    Screens beforeScreen = HOME;
    Screens currentScreen = HOME;

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

    void navigationMenu(const Font &myFont, Texture &textureCart, long long Subtotal);


    template <typename T>
    void HeadingAnimal(const Font &myFont, LinkedList<T> &list, vector<char*> &attributes) {
        // Nút thêm Pet
        Rectangle addPetButton = {450, 70, 60, 50};
        DrawRectangleRounded(addPetButton, 0.6, 10, GREEN);
        DrawTextEx(myFont, "+", (Vector2){addPetButton.x + addPetButton.width / 2 - MeasureTextEx(myFont, "+", 30, 2).x / 2, addPetButton.y + 10}, 30, 2, WHITE);

        // Xử lý nút addPet
        // Vẽ nền trắng bao quanh nội dung
        Rectangle background = {860, 80, 300, 620}; // Xác định vùng nền
        DrawRectangleRounded(background, 0.1f, 10, WHITE); // Vẽ nền với góc bo

        if(currentScreen == imagesDog) {
            // DrawTextEx(myFont, "Dog", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Dog", 60, 2).x / 2), 50}, 60, 2, darkGreen);

            // Căn chỉnh nội dung văn bản
            float textStartX = background.x + background.width / 2; // Căn giữa theo trục X
            float textStartY = background.y + 20;                 // Dịch xuống từ mép trên
            float lineSpacing = 40;                              // Khoảng cách giữa các dòng

            // Vẽ nội dung văn bản, căn giữa theo trục X
            DrawTextEx(myFont, "Purpose Of Raising", (Vector2){textStartX - MeasureTextEx(myFont, "Purpose Of Raising", 30, 2).x / 2, textStartY}, 35, 2, ORANGE);
            // Kiểm tra và vẽ "Pet"
            if (strcmp(attributes[0], "Pet") == 0) 
                DrawTextEx(myFont, "Pet", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Pet", 30, 2).x / 2, textStartY + lineSpacing}, 
                        30, 2, RED); // Nếu là "Pet", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Pet", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Pet", 30, 2).x / 2, textStartY + lineSpacing}, 
                        30, 2, darkGreen); // Nếu không phải "Pet", vẽ bằng màu xanh lá

            // Kiểm tra và vẽ "Companion"
            if (strcmp(attributes[0], "Companion") == 0) 
                DrawTextEx(myFont, "Companion", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Companion", 30, 2).x / 2, textStartY + 2 * lineSpacing}, 
                        30, 2, RED); // Nếu là "Companion", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Companion", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Companion", 30, 2).x / 2, textStartY + 2 * lineSpacing}, 
                        30, 2, darkGreen); // Nếu không phải "Companion", vẽ bằng màu xanh lá

            // Kiểm tra và vẽ "Guard"
            if (strcmp(attributes[0], "Guard") == 0) 
                DrawTextEx(myFont, "Guard", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Guard", 30, 2).x / 2, textStartY + 3 * lineSpacing}, 
                        30, 2, RED); // Nếu là "Guard", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Guard", 
                        (Vector2){textStartX - MeasureTextEx(myFont, "Guard", 30, 2).x / 2, textStartY + 3 * lineSpacing}, 
                        30, 2, darkGreen); // Nếu không phải "Guard", vẽ bằng màu xanh lá
            
            // Kiểm tra nếu nhấn vào các thuộc tính và lưu vào vector
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Purpose Of Raising", 30, 2).x / 2, textStartY, MeasureTextEx(myFont, "Purpose Of Raising", 30, 2).x, 30})) {
                attributes[0] = strdup("");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Pet", 30, 2).x / 2, textStartY + lineSpacing, MeasureTextEx(myFont, "Pet", 30, 2).x, 30})) {
                attributes[0] = strdup("Pet");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Companion", 30, 2).x / 2, textStartY + 2 * lineSpacing, MeasureTextEx(myFont, "Companion", 30, 2).x, 30})) {
                attributes[0] = strdup("Companion");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Guard", 30, 2).x / 2, textStartY + 3 * lineSpacing, MeasureTextEx(myFont, "Guard", 30, 2).x, 30})) {
                attributes[0] = strdup("Guard");
            }

            DrawTextEx(myFont, "Level Of Training", (Vector2){textStartX - MeasureTextEx(myFont, "Level Of Training", 30, 2).x / 2, textStartY + 4 * lineSpacing}, 35, 2, ORANGE);
            if (strcmp(attributes[1], "Kindergarten") == 0) 
                DrawTextEx(myFont, "Kindergarten", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Kindergarten", 30, 2).x / 2, textStartY + 5 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Kindergarten", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Kindergarten", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Kindergarten", 30, 2).x / 2, textStartY + 5 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Kindergarten", vẽ bằng màu xanh lá

            if (strcmp(attributes[1], "Grade school") == 0) 
                DrawTextEx(myFont, "Grade school", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Grade school", 30, 2).x / 2, textStartY + 6 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Grade school", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Grade school", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Grade school", 30, 2).x / 2, textStartY + 6 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Grade school", vẽ bằng màu xanh lá

            if (strcmp(attributes[1], "Junior High") == 0) 
                DrawTextEx(myFont, "Junior High", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Junior High", 30, 2).x / 2, textStartY + 7 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Junior High", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Junior High", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Junior High", 30, 2).x / 2, textStartY + 7 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Junior High", vẽ bằng màu xanh lá

            // Kiểm tra nếu nhấn vào các thuộc tính "Level Of Training" và lưu vào vector
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Level Of Training", 30, 2).x / 2, textStartY + 4 * lineSpacing, MeasureTextEx(myFont, "Level Of Training", 30, 2).x, 30})) {
                attributes[1] = strdup("");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Kindergarten", 30, 2).x / 2, textStartY + 5 * lineSpacing, MeasureTextEx(myFont, "Kindergarten", 30, 2).x, 30})) {
                attributes[1] = strdup("Kindergarten");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Grade school", 30, 2).x / 2, textStartY + 6 * lineSpacing, MeasureTextEx(myFont, "Grade school", 30, 2).x, 30})) {
                attributes[1] = strdup("Grade school");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Junior High", 30, 2).x / 2, textStartY + 7 * lineSpacing, MeasureTextEx(myFont, "Junior High", 30, 2).x, 30})) {
                attributes[1] = strdup("Junior High");
            }

            DrawTextEx(myFont, "Need For Exercise", (Vector2){textStartX - MeasureTextEx(myFont, "Need For Exercise", 30, 2).x / 2, textStartY + 8 * lineSpacing}, 35, 2, ORANGE);
            if (strcmp(attributes[2], "High") == 0) 
                DrawTextEx(myFont, "High", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "High", 30, 2).x / 2, textStartY + 9 * lineSpacing}, 
                            30, 2, RED); // Nếu là "High", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "High", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "High", 30, 2).x / 2, textStartY + 9 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "High", vẽ bằng màu xanh lá

            if (strcmp(attributes[2], "Medium") == 0) 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 10 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Medium", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 10 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Medium", vẽ bằng màu xanh lá

            if (strcmp(attributes[2], "Low") == 0) 
                DrawTextEx(myFont, "Low", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Low", 30, 2).x / 2, textStartY + 11 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Low", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Low", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Low", 30, 2).x / 2, textStartY + 11 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Low", vẽ bằng màu xanh lá

            // Kiểm tra nếu nhấn vào các thuộc tính "Need For Exercise" và lưu vào vector
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Need For Exercise", 30, 2).x / 2, textStartY + 8 * lineSpacing, MeasureTextEx(myFont, "Need For Exercise", 30, 2).x, 30})) {
                attributes[2] = strdup("");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "High", 30, 2).x / 2, textStartY + 9 * lineSpacing, MeasureTextEx(myFont, "High", 30, 2).x, 30})) {
                attributes[2] = strdup("High");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 10 * lineSpacing, MeasureTextEx(myFont, "Medium", 30, 2).x, 30})) {
                attributes[2] = strdup("Medium");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Low", 30, 2).x / 2, textStartY + 11 * lineSpacing, MeasureTextEx(myFont, "Low", 30, 2).x, 30})) {
                attributes[2] = strdup("Low");
            }
        }
        if(currentScreen == imagesCat) {
            // DrawTextEx(myFont, "Cat", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Cat", 60, 2).x / 2), 50}, 60, 2, darkGreen);

            // Căn chỉnh nội dung văn bản cho mèo
            float textStartX = background.x + background.width / 2; // Căn giữa theo trục X
            float textStartY = background.y + 20;                 // Dịch xuống từ mép trên
            float lineSpacing = 40;                              // Khoảng cách giữa các dòng

            // Vẽ nội dung văn bản cho các thuộc tính của mèo
            DrawTextEx(myFont, "Coat Color", (Vector2){textStartX - MeasureTextEx(myFont, "Coat Color", 30, 2).x / 2, textStartY}, 35, 2, ORANGE);
           if (strcmp(attributes[0], "One color") == 0) 
                DrawTextEx(myFont, "One color", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "One color", 30, 2).x / 2, textStartY + lineSpacing}, 
                            30, 2, RED); // Nếu là "One color", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "One color", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "One color", 30, 2).x / 2, textStartY + lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "One color", vẽ bằng màu xanh lá

            if (strcmp(attributes[0], "Multicolor") == 0) 
                DrawTextEx(myFont, "Multicolor", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Multicolor", 30, 2).x / 2, textStartY + 2 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Multicolor", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Multicolor", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Multicolor", 30, 2).x / 2, textStartY + 2 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Multicolor", vẽ bằng màu xanh lá

            // Kiểm tra nếu nhấn vào các thuộc tính và lưu vào vector
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Coat Color", 30, 2).x / 2, textStartY, MeasureTextEx(myFont, "Coat Color", 30, 2).x, 30})) {
                attributes[0] = strdup("");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "One color", 30, 2).x / 2, textStartY + lineSpacing, MeasureTextEx(myFont, "One color", 30, 2).x, 30})) {
                attributes[0] = strdup("One color");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Multicolor", 30, 2).x / 2, textStartY + 2 * lineSpacing, MeasureTextEx(myFont, "Multicolor", 30, 2).x, 30})) {
                attributes[0] = strdup("Multicolor");
            }

            DrawTextEx(myFont, "Popularity", (Vector2){textStartX - MeasureTextEx(myFont, "Popularity", 30, 2).x / 2, textStartY + 3 * lineSpacing}, 35, 2, ORANGE);
            if (strcmp(attributes[1], "Widespread") == 0) 
                DrawTextEx(myFont, "Widespread", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Widespread", 30, 2).x / 2, textStartY + 4 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Widespread", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Widespread", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Widespread", 30, 2).x / 2, textStartY + 4 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Widespread", vẽ bằng màu xanh lá

            if (strcmp(attributes[1], "Medium") == 0) 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 5 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Medium", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 5 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Medium", vẽ bằng màu xanh lá

            if (strcmp(attributes[1], "Rare") == 0) 
                DrawTextEx(myFont, "Rare", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Rare", 30, 2).x / 2, textStartY + 6 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Rare", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Rare", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Rare", 30, 2).x / 2, textStartY + 6 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Rare", vẽ bằng màu xanh lá

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Popularity", 30, 2).x / 2, textStartY + 3 * lineSpacing, MeasureTextEx(myFont, "Popularity", 30, 2).x, 30})) {
                attributes[1] = strdup("");
            }
            // Kiểm tra và lưu lựa chọn cho "Popularity"
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Widespread", 30, 2).x / 2, textStartY + 4 * lineSpacing, MeasureTextEx(myFont, "Widespread", 30, 2).x, 30})) {
                attributes[1] = strdup("Widespread");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 5 * lineSpacing, MeasureTextEx(myFont, "Medium", 30, 2).x, 30})) {
                attributes[1] = strdup("Medium");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Rare", 30, 2).x / 2, textStartY + 6 * lineSpacing, MeasureTextEx(myFont, "Rare", 30, 2).x, 30})) {
                attributes[1] = strdup("Rare");
            }

            DrawTextEx(myFont, "Shedding Level", (Vector2){textStartX - MeasureTextEx(myFont, "Shedding Level", 30, 2).x / 2, textStartY + 7 * lineSpacing}, 35, 2, ORANGE);
            if (strcmp(attributes[2], "Little") == 0) 
                DrawTextEx(myFont, "Little", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Little", 30, 2).x / 2, textStartY + 8 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Little", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Little", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Little", 30, 2).x / 2, textStartY + 8 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Little", vẽ bằng màu xanh lá

            if (strcmp(attributes[2], "Medium") == 0) 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 9 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Medium", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Medium", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 9 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Medium", vẽ bằng màu xanh lá

            if (strcmp(attributes[2], "Much") == 0) 
                DrawTextEx(myFont, "Much", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Much", 30, 2).x / 2, textStartY + 10 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Much", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Much", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Much", 30, 2).x / 2, textStartY + 10 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Much", vẽ bằng màu xanh lá

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Shedding Level", 30, 2).x / 2, textStartY + 7 * lineSpacing, MeasureTextEx(myFont, "Shedding Level", 30, 2).x, 30})) {
                attributes[2] = strdup("");
            }
            // Kiểm tra và lưu lựa chọn cho "Shedding Level"
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Little", 30, 2).x / 2, textStartY + 8 * lineSpacing, MeasureTextEx(myFont, "Little", 30, 2).x, 30})) {
                attributes[2] = strdup("Little");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Medium", 30, 2).x / 2, textStartY + 9 * lineSpacing, MeasureTextEx(myFont, "Medium", 30, 2).x, 30})) {
                attributes[2] = strdup("Medium");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Much", 30, 2).x / 2, textStartY + 10 * lineSpacing, MeasureTextEx(myFont, "Much", 30, 2).x, 30})) {
                attributes[2] = strdup("Much");
            }

            DrawTextEx(myFont, "Appearance", (Vector2){textStartX - MeasureTextEx(myFont, "Appearance", 30, 2).x / 2, textStartY + 11 * lineSpacing}, 35, 2, ORANGE);
            if (strcmp(attributes[3], "Noble") == 0) 
                DrawTextEx(myFont, "Noble", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Noble", 30, 2).x / 2, textStartY + 12 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Noble", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Noble", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Noble", 30, 2).x / 2, textStartY + 12 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Noble", vẽ bằng màu xanh lá

            if (strcmp(attributes[3], "Lovely") == 0) 
                DrawTextEx(myFont, "Lovely", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Lovely", 30, 2).x / 2, textStartY + 13 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Lovely", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Lovely", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Lovely", 30, 2).x / 2, textStartY + 13 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Lovely", vẽ bằng màu xanh lá

            if (strcmp(attributes[3], "Unique") == 0) 
                DrawTextEx(myFont, "Unique", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Unique", 30, 2).x / 2, textStartY + 14 * lineSpacing}, 
                            30, 2, RED); // Nếu là "Unique", vẽ bằng màu đỏ
            else 
                DrawTextEx(myFont, "Unique", 
                            (Vector2){textStartX - MeasureTextEx(myFont, "Unique", 30, 2).x / 2, textStartY + 14 * lineSpacing}, 
                            30, 2, darkGreen); // Nếu không phải "Unique", vẽ bằng màu xanh lá

            // Kiểm tra và lưu lựa chọn cho "Appearance"
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Appearance", 30, 2).x / 2, textStartY + 11 * lineSpacing, MeasureTextEx(myFont, "Appearance", 30, 2).x, 30})) {
                attributes[3] = strdup("");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Noble", 30, 2).x / 2, textStartY + 12 * lineSpacing, MeasureTextEx(myFont, "Noble", 30, 2).x, 30})) {
                attributes[3] = strdup("Noble");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Lovely", 30, 2).x / 2, textStartY + 13 * lineSpacing, MeasureTextEx(myFont, "Lovely", 30, 2).x, 30})) {
                attributes[3] = strdup("Lovely");
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), {textStartX - MeasureTextEx(myFont, "Unique", 30, 2).x / 2, textStartY + 14 * lineSpacing, MeasureTextEx(myFont, "Unique", 30, 2).x, 30})) {
                attributes[3] = strdup("Unique");
            }
        }
        // Thanh tìm kiếm
        string search = string(attributes[4]);
        DrawInputBox(myFont, search, 110, 70, 300, 50, 20);
        attributes[4] = strdup(search.c_str());
        // Button
        backButton(myFont);
        previousButton(myFont,list);
        nextButton(myFont,list);
    }
    
    template <typename T>
    void getNode(LinkedList<T> &list, Node<T>* &NodeAnimal, vector<char*> attributes, unsigned int &purQuant) {
        // Kiểm tra nếu chuột được nhấn
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 index = GetMousePosition();

            // Xác định node phù hợp dựa trên màn hình hiện tại
            if (currentScreen == imagesDog || currentScreen == imagesCat) {
                NodeAnimal = list.GetNodeFromAnimal(index, attributes);
            } 
            // else if (currentScreen == CART) {
            //     Node<pair<T, int>>* selectedCartNode = list.GetNodeFromCart(index);
            //     NodeAnimal = new Node<T>{selectedCartNode->getData().first}; // Tạo node T từ pair
            // } 
            else {
                NodeAnimal = NULL;
            }

            // Nếu NodeAnimal hợp lệ, kiểm tra loại đối tượng
            if (NodeAnimal != NULL) {
                purQuant = 1;
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
    // Hàm hiển thị thông báo trong 2 giây
    bool ShowPopup(const Font &myFont, const char* message, int width, int height);
    bool inputInforNewItem(const Font &myFont, Texture &texture, vector<string> &InforNewItem, int Type);
    void displayHistory(const Font &myFont, Texture &texture, vector<Customer*> Customers);
};