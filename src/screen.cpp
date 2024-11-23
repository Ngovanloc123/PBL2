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

// bool Screen::checkLoginButton(const Font &myFont)
// {
//     Rectangle buttonLogin = {(float(widthWindow) - 110), 10, 100, 50};
//     // DrawRectangleRounded(buttonLogin, 0.6, 10, lightGray);
//     // DrawTextEx(myFont, "Login", (Vector2){buttonLogin.x + buttonLogin.width / 2 - MeasureTextEx(myFont, "Login", 30, 2).x / 2, buttonLogin.y + 10}, 30, 2, darkGreen);

//     // nút thêm giỏ hàng
//     Rectangle AddToCart = {(float)(248 + 8 + 100 + 100), 500, 200, 60};

//     // Nút mua hàng
//     Rectangle buyNow = {(float)(248 + 8 + 100 + 240 * 3 / 2 + 100), 500, 200, 50};
    
//     // Nếu nhấn vào các nút trên thì đăng nhập
//     if (CheckCollisionPointRec(GetMousePosition(), buttonLogin) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//         return true;
//     }
//     if (CheckCollisionPointRec(GetMousePosition(), AddToCart) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//         return true;
//     }
//     if (CheckCollisionPointRec(GetMousePosition(), buyNow) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//         return true;
//     }
//     return false;
// }

void Screen::DrawInputBox(const Font &font, string &inputText, int boxX, int boxY, int boxWidth, int boxHeight, int maxChars)
{
    static bool isFocused = false; // Xác định ô nhập liệu có được chọn hay không

    // Kiểm tra sự kiện chuột để xác định trạng thái focus
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePosition, { (float)boxX, (float)boxY, (float)boxWidth, (float)boxHeight })) {
            isFocused = true;
        } else {
            isFocused = false;
        }
    }

    // Xử lý đầu vào từ bàn phím nếu ô nhập liệu đang focus
    if (isFocused) {
        int key = GetCharPressed(); // Lấy ký tự người dùng nhập vào

        // Xử lý ký tự nhập, không lấy phím space = 32
        while (key > 0) {
            if ((key == 32 || ((key >= 48) && (key <= 57)) || ((key >= 65) && (key <= 90)) || ((key >= 97) && (key <= 122))) && (static_cast<int>(inputText.length()) < maxChars)) {
                inputText += (char)key; // Thêm ký tự vào chuỗi
            }
            key = GetCharPressed(); // Tiếp tục xử lý các ký tự còn lại
        }

        // Xóa ký tự cuối khi nhấn Backspace hoặc nhấn phím space

        if (IsKeyDown(KEY_BACKSPACE) && !inputText.empty()) {
            inputText.pop_back();
        }
    }

    // Vẽ ô nhập liệu
    DrawRectangle(boxX, boxY, boxWidth, boxHeight, isFocused ? LIGHTGRAY : GRAY); // Thay đổi màu khi focus
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, BLACK);

    // Hiển thị văn bản người dùng đã nhập
    DrawTextEx(font, inputText.c_str(), { (float)boxX + 10, (float)boxY + 10 }, boxHeight * 0.5f, 2, BLACK);

    // Gợi ý khi ô nhập liệu trống và không focus
    if (inputText.empty() && !isFocused) {
        DrawTextEx(font, "Search", { (float)boxX + 10, (float)boxY + 10 }, boxHeight * 0.5f, 2, DARKGRAY);
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
    login = false;
    InitWindow(widthWindow, heightWindow, "Shop Pet");
    // Set FPS
    SetTargetFPS(60);
    // Load Texture
    Image image = LoadImage("image/background.png");
    textureMenu = LoadTextureFromImage(image);
    UnloadImage(image);
}


void Screen::backGround()
{
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

void Screen::navigationMenu(const Font &myFont, Texture &textureCart, long long Subtotal) {
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
    Rectangle buttonCart = {(float)((widthWindow) - 280), 20, 80, 40};
    Image imageCart = loadImageCart();
    textureCart = LoadTextureFromImage(imageCart);
    UnloadImage(imageCart);
    // DrawRectangleRounded(buttonCart, 0.6, 10, yellow);
    DrawTexture(textureCart, buttonCart.x, buttonCart.y, WHITE);
    // DrawTextEx(myFont, "Cart", (Vector2){buttonCart.x + buttonCart.width / 2 - MeasureTextEx(myFont, "Cart", 30, 2).x / 2, buttonCart.y + 10}, 30, 2, darkGreen);
    // Nút tổng thanh toán
    char fullText[50]; // Kích thước lớn để chứa giá trị lớn, khoảng cách, và " VND"

    // Chuyển số thành chuỗi
    sprintf(fullText, "%lld", Subtotal);

    // Thêm khoảng cách vào chuỗi giá tiền
    int len = strlen(fullText);
    int insertCount = 0;
    for (int i = len - 1; i > 0; --i) {
        if ((len - i) % 3 == 0) {
            for (int j = len + insertCount; j > i; --j) {
                fullText[j] = fullText[j - 1];
            }
            fullText[i] = ' ';
            insertCount++;
        }
    }
    fullText[len + insertCount] = '\0'; // Kết thúc chuỗi

    // Thêm " VND" vào cuối chuỗi
    strcat(fullText, " VND");

    Rectangle buttonSubtotal = {(float(widthWindow) - 220), 20, 200, 50};
    DrawRectangleRounded(buttonSubtotal, 0.3, 10, YELLOW);
    DrawTextEx(myFont, fullText, (Vector2){buttonSubtotal.x + buttonSubtotal.width / 2 - MeasureTextEx(myFont, fullText, 30, 2).x / 2, buttonSubtotal.y + 20}, 30, 2, darkGreen);


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

    // Quan trọng , xữ lý nút mua hàng
    
    //----------------------------------------------------------------
    // Nút đăng nhập
    // Rectangle buttonLogin = {(float(widthWindow) - 110), 10, 100, 50};
    // DrawTextEx(myFont, "Login", (Vector2){buttonLogin.x + buttonLogin.width / 2 - MeasureTextEx(myFont, "Login", 30, 2).x / 2, buttonLogin.y + 10}, 30, 2, darkGreen);

    // // Nút đăng ký
    // Rectangle buttonRegister = {(float(widthWindow) - 110), 60, 100, 50};
    // DrawTextEx(myFont, "Register", (Vector2){buttonRegister.x + buttonRegister.width / 2 - MeasureTextEx(myFont, "Register", 30, 2).x / 2, buttonRegister.y + 10}, 30, 2, darkGreen);

}


void Screen::Heading(const Font &myFont)
{
    if(currentScreen == INTRO)
        DrawTextEx(myFont, "Introduction", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Introduction", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == CONTACT)
        DrawTextEx(myFont, "Contact", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Contact", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == shoppingCart)
        DrawTextEx(myFont, "Shopping Cart", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "shoppingCart", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    // Back
    backButton(myFont);
}

void Screen::ShowPopup(const Font &myFont, const char *message, int width, int height) {
    // Tính toán vị trí hộp thông báo ở giữa màn hình
    Rectangle popupRect = {
        (float)((GetScreenWidth() - width) / 2),
        (float)((GetScreenHeight() - height) / 2),
        (float)width,
        (float)height
    };

    // Tính toán vị trí nút xóa (OK button)
    int buttonWidth = 100;
    int buttonHeight = 40;
    Rectangle buttonRect = {
        popupRect.x + (popupRect.width - buttonWidth) / 2,
        popupRect.y + popupRect.height - buttonHeight - 10,
        (float)buttonWidth,
        (float)buttonHeight
    };

    bool buttonClicked = false;

    // Vòng lặp hiển thị thông báo
    while (!buttonClicked && !WindowShouldClose()) {
        // Kiểm tra nếu người dùng nhấn chuột vào nút
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, buttonRect)) {
                buttonClicked = true;
            }
        }

        BeginDrawing();
        // ClearBackground(RAYWHITE);

        // Vẽ hộp thông báo
        DrawRectangleRounded(popupRect, 0.2f, 10, RAYWHITE);
        DrawRectangleRoundedLines(popupRect, 0.2f, 10, 2, BLACK);

        // Hiển thị thông báo với font tùy chỉnh
        int fontSize = 30;
        Vector2 textSize = MeasureTextEx(myFont, message, fontSize, 2);
        DrawTextEx(myFont, message, {popupRect.x + (popupRect.width - textSize.x) / 2, popupRect.y + (popupRect.height - textSize.y) / 2 - 20}, fontSize, 2, BLACK);

        // Vẽ nút xóa (OK button)
        DrawRectangleRounded(buttonRect, 0.2f, 10, LIGHTGRAY);
        DrawRectangleRoundedLines(buttonRect, 0.2f, 10, 2, BLACK);

        // Hiển thị chữ "OK" trên nút
        const char *buttonText = "OK";
        Vector2 buttonTextSize = MeasureTextEx(myFont, buttonText, 20, 2);
        DrawTextEx(myFont, buttonText, 
                   {buttonRect.x + (buttonRect.width - buttonTextSize.x) / 2, buttonRect.y + (buttonRect.height - buttonTextSize.y) / 2}, 
                   20, 2, BLACK);

        EndDrawing();
    }
}

// bool Screen::isLogin()
// {
//     return login;
// }

// void Screen::Login(const Font &myFont, Texture &texture) {
//     if (checkLoginButton(myFont)) {
//         const int loginWidth = 440;
//         const int loginHeight = 712;
//         SetWindowSize(loginWidth, loginHeight); // Thay đổi kích thước cửa sổ

//         while(!WindowShouldClose()) {
//             BeginDrawing();
//             ClearBackground(RAYWHITE);

//             // Tỷ lệ vị trí và kích thước dựa trên kích thước cửa sổ
//             float formWidth = loginWidth * 0.8f;   // Chiều rộng form (80% chiều rộng cửa sổ)
//             float formX = (loginWidth - formWidth) / 2.0f;  // Căn giữa theo chiều ngang

//             // Tiêu đề
//             DrawTextEx(myFont, "LOGIN", (Vector2){(float)(loginWidth / 2 - MeasureTextEx(myFont, "LOGIN", 60, 2).x / 2), 50}, 60, 2, darkGreen);

//             // Ô nhập liệu
//             DrawRectangle(formX, loginHeight * 0.2f, formWidth, loginHeight * 0.07f, LIGHTGRAY);  // Username box
//             DrawRectangle(formX, loginHeight * 0.3f, formWidth, loginHeight * 0.07f, LIGHTGRAY);  // Password box
//             DrawTextEx(myFont, "User name", {formX + 10, loginHeight * 0.21f}, loginHeight * 0.035f, 2, GRAY);
//             DrawTextEx(myFont, "********", {formX + 10, loginHeight * 0.31f}, loginHeight * 0.035f, 2, GRAY);

//             // Checkbox + Forgot Password
//             float checkboxSize = loginHeight * 0.03f;
//             DrawRectangle(formX, loginHeight * 0.4f, checkboxSize, checkboxSize, GRAY);  // Checkbox
//             DrawTextEx(myFont, "Remember me", {formX + checkboxSize + 10, loginHeight * 0.4f}, loginHeight * 0.03f, 2, DARKGRAY);
//             DrawTextEx(myFont, "Forgot Password?", {formX + formWidth - 140, loginHeight * 0.4f}, loginHeight * 0.03f, 2, BLUE);

//             // Nút "Login"
//             DrawRectangle(formX + formWidth * 0.25f, loginHeight * 0.5f, formWidth * 0.5f, loginHeight * 0.07f, RED);
//             DrawTextEx(myFont, "Login", {formX + formWidth * 0.4f, loginHeight * 0.515f}, loginHeight * 0.035f, 2, WHITE);

//             // Divider ("OR")
//             DrawTextEx(myFont, "or", {loginWidth / 2.0f - 10, loginHeight * 0.6f}, loginHeight * 0.03f, 2, GRAY);

//             // Nút Facebook
//             DrawRectangle(formX, loginHeight * 0.65f, formWidth * 0.45f, loginHeight * 0.07f, DARKBLUE);
//             DrawTextEx(myFont, "Facebook", {formX + 20, loginHeight * 0.665f}, loginHeight * 0.03f, 2, WHITE);

//             // Nút Twitter
//             DrawRectangle(formX + formWidth * 0.55f, loginHeight * 0.65f, formWidth * 0.45f, loginHeight * 0.07f, SKYBLUE);
//             DrawTextEx(myFont, "Twitter", {formX + formWidth * 0.55f + 20, loginHeight * 0.665f}, loginHeight * 0.03f, 2, WHITE);

//             EndDrawing();
//         }
//         // Set về kích thước ban đầu
//         SetWindowSize(widthWindow, heightWindow);
//     }
// }
