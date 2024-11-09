#include "screen.h"

void Screen::backButton(const Font &myFont)
 {
    // Back
    Rectangle buttonBack = {10, 20, 50, 50};
    // DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
    DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(beforeScreen == shoppingCart && currentScreen == detailDog) {
            beforeScreen = currentScreen;
            currentScreen = shoppingCart;
        }
        else
        if(currentScreen == detailDog) {
            beforeScreen = currentScreen;
            currentScreen = imagesDog;
        }
        else
        if(currentScreen == detailCat) {
            beforeScreen = currentScreen;
            currentScreen = imagesCat;
        }
        else
        // Lỗi ở đây, không thể chuyển về shopping cart và chuyển thẳng vè home???
        if(currentScreen == imagesDog || currentScreen == imagesCat || currentScreen == INTRO || currentScreen == CONTACT || currentScreen == shoppingCart) {
            beforeScreen = currentScreen;
            currentScreen = HOME;
        }

    }
}

Image Screen::loadImageCart()
 {
    Image image = LoadImage("image/shopping-cart.png");
    ImageResize(&image, 40, 40);
    return image;
}

Screen::Screen()
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

void Screen::backGround() {
    int posX = (widthWindow - textureMenu.width) / 2;
    int posY = (heightWindow - textureMenu.height) / 2;
    DrawTexture(textureMenu, posX, posY, WHITE);
}

void Screen::DrawHome(const Font &myFont) {
    // Giới thiệu
    DrawTextEx(myFont, "WELCOME", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "WELCOME", 60, 2).x / 2), 100}, 60, 2, darkGreen);
    DrawTextEx(myFont, "TO", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "TO", 50, 2).x / 2), 170}, 50, 2, darkGreen);
    DrawTextEx(myFont, "ITPET", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "ITPET", 80, 2).x / 2), 210}, 80, 2, darkGreen);
}

void Screen::navigationMenu(const Font &myFont, Texture &textureCart) {
    // Nút Home
    Rectangle buttonHome = {80, 20, 80, 40};
    // DrawRectangleRounded(buttonHome, 0.6, 10, yellow);
    DrawTextEx(myFont, "Home", (Vector2){buttonHome.x + buttonHome.width / 2 - MeasureTextEx(myFont, "Home", 30, 2).x / 2, buttonHome.y + 10}, 30, 2, darkGreen);
    // Nút Dog
    Rectangle buttonDog = {190, 20, 80, 40};
    // DrawRectangleRounded(buttonDog, 0.6, 10, yellow);
    DrawTextEx(myFont, "Dog", (Vector2){buttonDog.x + buttonDog.width / 2 - MeasureTextEx(myFont, "Dog", 30, 2).x / 2, buttonDog.y + 10}, 30, 2, darkGreen);
    // Nút Cat
    Rectangle buttonCat = {280, 20, 80, 40};
    // DrawRectangleRounded(buttonCat, 0.6, 10, yellow);
    DrawTextEx(myFont, "Cat", (Vector2){buttonCat.x + buttonCat.width / 2 - MeasureTextEx(myFont, "Cat", 30, 2).x / 2, buttonCat.y + 10}, 30, 2, darkGreen);
    // Xử lý khi click vào Dog
    if(CheckCollisionPointRec(GetMousePosition(), buttonDog) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = imagesDog;
    }
    // Xử lý khi click vào Cat
    if(CheckCollisionPointRec(GetMousePosition(), buttonCat) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = imagesCat;
    }
//----------------------------------------------
    // Nút giới thiệu
    Rectangle buttonIntro = {380, 20, 150, 40};
    // DrawRectangleRounded(buttonIntro, 0.6, 10, yellow);
    DrawTextEx(myFont, "Introduction", (Vector2){buttonIntro.x + buttonIntro.width / 2 - MeasureTextEx(myFont, "Introduction", 30, 2).x / 2, buttonIntro.y + 10}, 30, 2, darkGreen);

    // Nút liên hệ
    Rectangle buttonContact = {540, 20, 120, 40};
    // DrawRectangleRounded(buttonContact, 0.6, 10, yellow);
    DrawTextEx(myFont, "Contact", (Vector2){buttonContact.x + buttonContact.width / 2 - MeasureTextEx(myFont, "Contact", 30, 2).x / 2, buttonContact.y + 10}, 30, 2, darkGreen);

    // Shopping Cart
    Rectangle buttonCart = {(float)((widthWindow) - 200), 20, 80, 40};
    Image imageCart = loadImageCart();
    textureCart = LoadTextureFromImage(imageCart);
    UnloadImage(imageCart);
    // DrawRectangleRounded(buttonCart, 0.6, 10, yellow);
    DrawTexture(textureCart, buttonCart.x, buttonCart.y, WHITE);
    // DrawTextEx(myFont, "Cart", (Vector2){buttonCart.x + buttonCart.width / 2 - MeasureTextEx(myFont, "Cart", 30, 2).x / 2, buttonCart.y + 10}, 30, 2, darkGreen);

    // Xử lý các nút
    if(CheckCollisionPointRec(GetMousePosition(), buttonHome) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = HOME;
    }
    if(CheckCollisionPointRec(GetMousePosition(), buttonIntro) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = INTRO;
    }
    if(CheckCollisionPointRec(GetMousePosition(), buttonContact) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = CONTACT;
    }
    if(CheckCollisionPointRec(GetMousePosition(), buttonCart) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = shoppingCart;
    }
}


void Screen::Heading(const Font &myFont)
{
    if(currentScreen == detailDog || currentScreen == detailDog)
        DrawTextEx(myFont, "Information", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Information", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == INTRO)
        DrawTextEx(myFont, "Introduction", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Introduction", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == CONTACT)
        DrawTextEx(myFont, "Contact", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Contact", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == shoppingCart)
        DrawTextEx(myFont, "Shopping Cart", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "shoppingCart", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    // Back
    backButton(myFont);
}
