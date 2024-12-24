#include "screen.h"

void Screen::backButton(const Font &myFont)
 {
    // Back
    Rectangle buttonBack = {10, 20, 50, 50};
    // DrawRectangleRounded(buttonBack, 0.6, 10, yellow);
    DrawTextEx(myFont, "<", (Vector2){buttonBack.x + buttonBack.width / 2 - MeasureTextEx(myFont, "<", 30, 2).x / 2, buttonBack.y + 10}, 30, 2, darkGreen);

    if(CheckCollisionPointRec(GetMousePosition(), buttonBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(beforeScreen == CART && currentScreen == detailDog) {
            beforeScreen = currentScreen;
            currentScreen = CART;
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
        if(currentScreen == imagesDog || currentScreen == imagesCat || currentScreen == INTRO || currentScreen == HISTORY || currentScreen == CART) {
            beforeScreen = currentScreen;
            currentScreen = HOME;
        }

    }
}

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
    Rectangle buttonHistory = {540, 20, 120, 40};
    // DrawRectangleRounded(buttonHistory, 0.6, 10, yellow);
    DrawTextEx(myFont, "History", (Vector2){buttonHistory.x + buttonHistory.width / 2 - MeasureTextEx(myFont, "History", 30, 2).x / 2, buttonHistory.y + 10}, 30, 2, darkGreen);

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
    if(CheckCollisionPointRec(GetMousePosition(), buttonHistory) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = HISTORY;
    }
    if(CheckCollisionPointRec(GetMousePosition(), buttonCart) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        beforeScreen = currentScreen;
        currentScreen = CART;
    }

}

void Screen::Heading(const Font &myFont)
{
    if(currentScreen == INTRO)
        DrawTextEx(myFont, "Introduction", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "Introduction", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == CART)
        DrawTextEx(myFont, "Shopping Cart", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "CART", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    if(currentScreen == HISTORY) {
        DrawTextEx(myFont, "History", (Vector2){(float)(widthWindow / 2 - MeasureTextEx(myFont, "History", 60, 2).x / 2), 50}, 60, 2, darkGreen);
    }
    // Back
    backButton(myFont);
}

bool Screen::ShowPopup(const Font &myFont, const char *message, int width, int height) {
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

    // Vòng lặp hiển thị thông báo
    while (true) {
        // Kiểm tra nếu người dùng nhấn chuột vào nút
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, buttonRect)) {
                // buttonClicked = true;
                return true;
            }
            else return false;
        }

        BeginDrawing();

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

bool Screen::inputInforNewItem(const Font &myFont, Texture &texture, vector<string> &InforNewItem, string type)
{
    vector<string> dogFields = {
        "Name", "Image Link", "Origin", "Average Age", "Fur Type", "Quantity", 
        "Selling Price", "Size", "Purpose of Raising", "Level of Training", "Need for Exercise" 
    };

    vector<string> catFields = { 
        "Name", "Image Link", "Origin", "Average Age", "Fur Type", "Quantity", 
        "Selling Price", "Size", "Coat Color", "Popularity", "Shedding Level", "Appearance" 
    };

    vector<string> fields;
    if(currentScreen == detailDog) fields = dogFields;
    else fields = catFields;

    if(!InforNewItem.size()) InforNewItem.resize(fields.size(), ""); 
    int boxWidth = 400, boxHeight = 60;
    string currentInput = InforNewItem[0];
    int currentFieldIndex = 0;

    const int newWindowWidth = 600;
    const int newWindowHeight = 900;

    // Tải hình ảnh
    Image image = LoadImage("image/background1.png");
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        // return false;
    }

    ImageResize(&image, newWindowWidth, newWindowHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Thay đổi kích thước màn hình
    SetWindowSize(newWindowWidth, newWindowHeight);

    while (true) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        
        // Hiển thị ảnh texture
        int posX = (newWindowWidth - texture.width) / 2;
        int posY = (newWindowHeight - texture.height) / 2;
        DrawTexture(texture, posX, posY, WHITE);

        // Hiển thị thông tin trường hiện tại
        DrawTextEx(myFont, fields[currentFieldIndex].c_str(), {50, 100}, boxHeight * 0.5f, 2, BLACK);

        // Vẽ và xử lý ô nhập liệu
        DrawInputBox(myFont, currentInput, 50, 150, boxWidth + 50, boxHeight, 100);

        // Hiển thị nút "Next"
        int nextButtonX = 350, nextButtonY = 150 + boxHeight + 20;
        int buttonWidth = 150, buttonHeight = 50;
        DrawRectangleRounded({ (float)nextButtonX - 50, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKGREEN);
        DrawTextEx(myFont, "Next", { (float)nextButtonX + 30, (float)nextButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "Back"
        int backButtonX = 100, backButtonY = nextButtonY;
        DrawRectangleRounded({ (float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "Back", { (float)backButtonX + 30, (float)backButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "OK"
        int okButtonX = 200, okButtonY = nextButtonY + 100;
        DrawRectangleRounded({ (float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKGRAY);
        DrawTextEx(myFont, "OK", { (float)okButtonX + 40, (float)okButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);
        
        // Hiển thị nút back "<"
        int backToMenuButtonX = 10, backToMenuButtonY = 10;
        DrawRectangleRounded({ (float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30 }, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "<", { (float)backToMenuButtonX + 5, (float)backToMenuButtonY + 5 }, boxHeight * 0.5f, 20, WHITE);

        // Xử lý sự kiện nhấn chuột
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();

            // Nhấn nút "Next"
            if (CheckCollisionPointRec(mousePosition, { (float)nextButtonX, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewItem[currentFieldIndex] = currentInput;
                if(type == "update" && currentFieldIndex == 4) currentFieldIndex += 2;
                if (currentFieldIndex < static_cast<int>(fields.size()) - 1) {
                    currentInput = InforNewItem[++currentFieldIndex];
                }
            }
            // Nhấn nút "Back"
            else if (CheckCollisionPointRec(mousePosition, { (float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewItem[currentFieldIndex] = currentInput;
                if(type == "update" && currentFieldIndex == 6) currentFieldIndex -= 2;
                if (currentFieldIndex > 0) {
                    currentInput = InforNewItem[--currentFieldIndex];
                }
            }
            // Nhấn nút "OK"
            else if (CheckCollisionPointRec(mousePosition, { (float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewItem[currentFieldIndex] = currentInput;

                // Kiểm tra và xử lý thông tin nhập
                for (size_t i = 0; i < fields.size(); ++i) {
                    if (i == 1 && InforNewItem[i].empty()) {
                        InforNewItem[i] = "image/Dogs/Unknown.png";
                    } else if (InforNewItem[i].empty() || !all_of(InforNewItem[i].begin(), InforNewItem[i].end(), [](char c) { return isdigit(c); })) {
                        if (i == 3 || i == 5 || i == 6 || i == 7) {
                            InforNewItem[i] = "0";
                        } else if (InforNewItem[i].empty()) {
                            InforNewItem[i] = "Unknown";
                        }
                    }
                }
        
                if (ShowPopup(myFont, "Do you want to save information?", 500, 100)) {
                    SetWindowSize(widthWindow, heightWindow);
                    return true;
                }
            }
            // Nhấn nút back "<"
            else if (CheckCollisionPointRec(mousePosition, { (float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30 })) {
                SetWindowSize(widthWindow, heightWindow);
                return false;
            }
        }
        EndDrawing();
    }
    SetWindowSize(widthWindow, heightWindow);
    return true;
}


int Screen::loadAnimalDetails(const Font &myFont, Texture &texture, vector<AnimalDetail *> &AnimalDetails, vector<string> InforNewItems, string type)
{
    vector<string> fields = {"Weight", "Sex"};
    int boxWidth = 400, boxHeight = 60;

    const int newWindowWidth = 600;
    const int newWindowHeight = 900;

    // Tải hình ảnh
    Image image = LoadImage("image/background1.png");
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
    }

    // Thay đổi kích thước hình ảnh
    ImageResize(&image, newWindowWidth, newWindowHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Thay đổi kích thước màn hình
    SetWindowSize(newWindowWidth, newWindowHeight);

    int quantity = 0; // Số lượng ban đầu là 0
    vector<vector<string>> collectedData;
    bool enteringQuantity = (type == "Add Quantity"); // Biến trạng thái để xác định đang nhập số lượng


    // Biến đếm thông pet hiện tại đang được nhập thông tin
    int currentAnimalIndex = 0;
    // Biến đếm thông tin đang được nhập
    int currentFieldIndex = 0;
    // Biến lưu thông tin sau khi nhập
    string currentInput = "";

    while (true)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Hiển thị ảnh texture
        int posX = (newWindowWidth - texture.width) / 2;
        int posY = (newWindowHeight - texture.height) / 2;
        DrawTexture(texture, posX, posY, WHITE);

        // Vẽ thông tin hiện tại
        if (enteringQuantity)
        {
            DrawTextEx(myFont, "Enter quantity:", {50, 50}, boxHeight * 0.5f, 2, BLACK);
        }
        else
        {
            DrawTextEx(myFont, (InforNewItems[0] + " " + to_string(currentAnimalIndex + 1) + "/" + to_string(quantity)).c_str(), {50, 50}, boxHeight * 0.5f, 2, BLACK);
            DrawTextEx(myFont, fields[currentFieldIndex].c_str(), {50, 100}, boxHeight * 0.5f, 2, BLACK);
        }

        // Vẽ ô nhập liệu, lưu thông tin nhập vào biến currentInput
        DrawInputBox(myFont, currentInput, 50, 150, boxWidth + 50, boxHeight, 100);

        // Hiển thị nút "Next"
        int nextButtonX = 350, nextButtonY = 150 + boxHeight + 20;
        int buttonWidth = 150, buttonHeight = 50;
        DrawRectangleRounded({(float)nextButtonX - 50, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight}, 0.2f, 10, DARKGREEN);
        DrawTextEx(myFont, "Next", {(float)nextButtonX + 30, (float)nextButtonY + 10}, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút back "<"
        int backToMenuButtonX = 10, backToMenuButtonY = 10;
        DrawRectangleRounded({(float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30}, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "<", {(float)backToMenuButtonX + 5, (float)backToMenuButtonY + 5}, boxHeight * 0.5f, 20, WHITE);

        // Xử lý sự kiện nhấn chuột
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();

            // Nhấn nút "Next"
            if (CheckCollisionPointRec(mousePosition, {(float)nextButtonX, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight}))
            {
                if (enteringQuantity)
                {
                    // try
                    // {
                        quantity = stoi(currentInput); // Số lượng muốn thêm vào
                        collectedData.resize(quantity, vector<string>(fields.size(), ""));
                        enteringQuantity = false; // Chuyển sang nhập thông tin chi tiết
                        currentInput = "";
                    // }
                    // catch (...)
                    // {
                    //     currentInput = ""; // Reset nếu nhập không hợp lệ
                    // }
                }
                else
                {
                    collectedData[currentAnimalIndex][currentFieldIndex] = currentInput;
                    if (currentFieldIndex < static_cast<int>(fields.size()) - 1)
                    {
                        currentFieldIndex++;
                        currentInput = "";
                    }
                    else
                    {
                        currentFieldIndex = 0;
                        currentInput = "";
                        if (++currentAnimalIndex >= quantity)
                        {
                            // Thêm dữ liệu vào AnimalDetails
                            for (const auto &data : collectedData)
                            {
                                AnimalDetail *newAnimal = new AnimalDetail(InforNewItems[0], data[0], data[1]);
                                AnimalDetails.push_back(newAnimal);
                            }
                            SetWindowSize(widthWindow, heightWindow);
                            return quantity;
                        }
                    }
                }
            }
            // Nhấn nút back "<"
            else if (CheckCollisionPointRec(mousePosition, {(float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30}))
            {
                SetWindowSize(widthWindow, heightWindow);
                return quantity;
            }
        }

        // Xử lý nhập liệu từ bàn phím
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125)) // Chỉ nhận ký tự ASCII
            {
                currentInput += (char)key;
            }
            key = GetCharPressed();
        }

        // Xóa thông tin
        if (IsKeyPressed(KEY_BACKSPACE) && !currentInput.empty())
        {
            currentInput.pop_back();
        }

        EndDrawing();
    }
    return quantity;
}

// Hàm nhập thông tin khách hàng
bool Screen::inputInforCustomer(const Font &myFont, Texture &texture, vector<string> &InforNewCustomer) {
    vector<string> customer = {
        "Name", "Phone Number", "Address"
    };

    if(!InforNewCustomer.size()) InforNewCustomer.resize(customer.size(), ""); 
    int boxWidth = 400, boxHeight = 60;
    string currentInput = InforNewCustomer[0];
    int currentFieldIndex = 0;

    const int newWindowWidth = 600;
    const int newWindowHeight = 900;

    // Tải hình ảnh
    Image image = LoadImage("image/background1.png");
    if (image.width == 0 || image.height == 0)
    {
        cout << "Failed to load image!" << endl;
        // return false;
    }

    ImageResize(&image, newWindowWidth, newWindowHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Thay đổi kích thước màn hình
    SetWindowSize(newWindowWidth, newWindowHeight);

    while (true) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        
        // Hiển thị ảnh texture
        int posX = (newWindowWidth - texture.width) / 2;
        int posY = (newWindowHeight - texture.height) / 2;
        DrawTexture(texture, posX, posY, WHITE);

        // Hiển thị thông tin trường hiện tại
        DrawTextEx(myFont, customer[currentFieldIndex].c_str(), {50, 100}, boxHeight * 0.5f, 2, BLACK);

        // Vẽ và xử lý ô nhập liệu
        DrawInputBox(myFont, currentInput, 50, 150, boxWidth + 50, boxHeight, 100);

        // Hiển thị nút "Next"
        int nextButtonX = 350, nextButtonY = 150 + boxHeight + 20;
        int buttonWidth = 150, buttonHeight = 50;
        DrawRectangleRounded({ (float)nextButtonX - 50, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKGREEN);
        DrawTextEx(myFont, "Next", { (float)nextButtonX + 30, (float)nextButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "Back"
        int backButtonX = 100, backButtonY = nextButtonY;
        DrawRectangleRounded({ (float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "Back", { (float)backButtonX + 30, (float)backButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "OK"
        int okButtonX = 200, okButtonY = nextButtonY + 100;
        DrawRectangleRounded({ (float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight }, 0.2f, 10, DARKGRAY);
        DrawTextEx(myFont, "OK", { (float)okButtonX + 40, (float)okButtonY + 10 }, boxHeight * 0.5f, 2, WHITE);
        
        // Hiển thị nút back "<"
        int backToMenuButtonX = 10, backToMenuButtonY = 10;
        DrawRectangleRounded({ (float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30 }, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "<", { (float)backToMenuButtonX + 5, (float)backToMenuButtonY + 5 }, boxHeight * 0.5f, 20, WHITE);

        // Xử lý sự kiện nhấn chuột
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();

            // Nhấn nút "Next"
            if (CheckCollisionPointRec(mousePosition, { (float)nextButtonX, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewCustomer[currentFieldIndex] = currentInput;
                if (currentFieldIndex < static_cast<int>(customer.size()) - 1) {
                    currentInput = InforNewCustomer[++currentFieldIndex];
                }
            }
            // Nhấn nút "Back"
            else if (CheckCollisionPointRec(mousePosition, { (float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewCustomer[currentFieldIndex] = currentInput;
                if (currentFieldIndex > 0) {
                    currentInput = InforNewCustomer[--currentFieldIndex];
                }
            }
            // Nhấn nút "OK"
            else if (CheckCollisionPointRec(mousePosition, { (float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight })) {
                InforNewCustomer[currentFieldIndex] = currentInput;
                int check = 0;
                for (size_t i = 0; i < customer.size(); ++i) {
                    if (InforNewCustomer[i].empty()) {
                        ShowPopup(myFont, "Information cannot be left blank!", 500, 100);
                        break;
                    }
                    check++;
                }
                if (check == static_cast<int>(customer.size())) {
                    if (ShowPopup(myFont, "Do you want to save information?", 500, 100)) {
                        SetWindowSize(widthWindow, heightWindow);
                        return true;
                    }
                }
            }
            // Nhấn nút back "<"
            else if (CheckCollisionPointRec(mousePosition, { (float)backToMenuButtonX, (float)backToMenuButtonY, 30, 30 })) {
                SetWindowSize(widthWindow, heightWindow);
                return false;
            }
        }
        EndDrawing();
    }
    SetWindowSize(widthWindow, heightWindow);
    return true;
}


void Screen::inputIdPet(const Font &myFont, Texture &texture, vector<Item> &Items, vector<unsigned int> &petId, vector<AnimalDetail *> &animalDetails) {
    int boxWidth = 400, boxHeight = 60;
    string currentInput = "";  // Dùng để lưu ID nhập vào
    int currentFieldIndex = 0;  // Chỉ số mục hiện tại
    int totalItemsToBuy = 0;  // Tổng số lượng pet cần nhập ID

    // Tính tổng số lượng cần nhập ID
    for (Item &item : Items) {
        totalItemsToBuy += item.getQuantity();
    }
    cout << totalItemsToBuy << endl;

    const int newWindowWidth = 600;
    const int newWindowHeight = 900;

    // Tải hình ảnh
    Image image = LoadImage("image/background1.png");
    if (image.width == 0 || image.height == 0) {
        cout << "Failed to load image!" << endl;
        return;
    }

    ImageResize(&image, newWindowWidth, newWindowHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Thay đổi kích thước màn hình
    SetWindowSize(newWindowWidth, newWindowHeight);

    while (true) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Hiển thị ảnh texture
        int posX = (newWindowWidth - texture.width) / 2;
        int posY = (newWindowHeight - texture.height) / 2;
        DrawTexture(texture, posX, posY, WHITE);



        // Hiển thị tên pet và ID
        int itemIndex;
        string petName;
        if (currentFieldIndex < totalItemsToBuy) {
            itemIndex = 0;
            int remainingQuantity = currentFieldIndex;
            while (remainingQuantity >= Items[itemIndex].getQuantity()) {
                remainingQuantity -= Items[itemIndex].getQuantity();
                itemIndex++;
            }

            petName = Items[itemIndex].getName(); // Lấy tên pet
            DrawTextEx(myFont, ("Enter ID for " + petName).c_str(), {50, 100}, boxHeight * 0.5f, 2, BLACK);
        }

        // Vẽ và xử lý ô nhập liệu
        DrawInputBox(myFont, currentInput, 50, 150, boxWidth + 50, boxHeight, 100);

        // Hiển thị nút "Next"
        int nextButtonX = 350, nextButtonY = 150 + boxHeight + 20;
        int buttonWidth = 150, buttonHeight = 50;
        DrawRectangleRounded({(float)nextButtonX - 50, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight}, 0.2f, 10, DARKGREEN);
        DrawTextEx(myFont, "Next", {(float)nextButtonX + 30, (float)nextButtonY + 10}, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "Back"
        int backButtonX = 100, backButtonY = nextButtonY;
        DrawRectangleRounded({(float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight}, 0.2f, 10, DARKBLUE);
        DrawTextEx(myFont, "Back", {(float)backButtonX + 30, (float)backButtonY + 10}, boxHeight * 0.5f, 2, WHITE);

        // Hiển thị nút "OK"
        int okButtonX = 200, okButtonY = nextButtonY + 100;
        DrawRectangleRounded({(float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight}, 0.2f, 10, DARKGRAY);
        DrawTextEx(myFont, "OK", {(float)okButtonX + 40, (float)okButtonY + 10}, boxHeight * 0.5f, 2, WHITE);

        // Xử lý sự kiện nhấn chuột
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();

            // Nhấn nút "Next"
            if (CheckCollisionPointRec(mousePosition, {(float)nextButtonX, (float)nextButtonY, (float)buttonWidth, (float)buttonHeight})) {
                if (!currentInput.empty()) {
                    unsigned int currentId = std::stoul(currentInput);

                    // Kiểm tra xem ID có đúng không và trạng thái có bật hay không
                    bool isValidId = false;
                    for (auto &animalDetail : animalDetails) {
                        // Kiểm tra nếu tên pet khớp với tên trong danh sách Items
                        if (animalDetail->getName() == petName) {
                            // Sau khi tên khớp, kiểm tra ID và trạng thái
                            if (animalDetail->getId() == currentId && animalDetail->getStatus() != 0) {
                                // Kiểm tra xem ID đã được nhập trước đó chưa
                                bool idAlreadyEntered = false;
                                for (unsigned int enteredId : petId) {
                                    if (enteredId == currentId) {
                                        idAlreadyEntered = true;
                                        break;
                                    }
                                }

                                if (!idAlreadyEntered) {
                                    isValidId = true;
                                }
                                break;
                            }
                        }
                    }

                    if (isValidId) {
                        // ID hợp lệ, tiếp tục xử lý
                    } else {
                        ShowPopup(myFont, "ID does not match the pet name or status is not active!", 500, 100);
                    }


                    // Nếu ID không hợp lệ, thông báo lỗi
                    if (!isValidId) {
                        ShowPopup(myFont, "Invalid ID, status, or pet name mismatch!", 500, 100);
                    }


                    if (isValidId) {
                        petId.push_back(currentId);
                        if (petId.size() < totalItemsToBuy) {
                            currentFieldIndex++;
                            currentInput = "";  // Reset ô nhập liệu
                        }
                        cout << currentFieldIndex << endl;
                    } else {
                        ShowPopup(myFont, "Invalid ID or status!", 500, 100);
                    }
                }
            }

            // Nhấn nút "Back"
            else if (CheckCollisionPointRec(mousePosition, {(float)backButtonX, (float)backButtonY, (float)buttonWidth, (float)buttonHeight})) {
                if (currentFieldIndex > 0) {
                    currentFieldIndex--;
                    currentInput = "";
                    petId.pop_back();
                }
            }

            // Nhấn nút "OK"
            else if (CheckCollisionPointRec(mousePosition, {(float)okButtonX, (float)okButtonY, (float)buttonWidth, (float)buttonHeight})) {
                if (!currentInput.empty()) {
                    unsigned int currentId = std::stoul(currentInput);

                    // Kiểm tra xem ID có đúng không và trạng thái có bật hay không
                    bool isValidId = false;
                    for (auto &animalDetail : animalDetails) {
                        // Kiểm tra nếu tên pet khớp với tên trong danh sách Items
                        if (animalDetail->getName() == petName) {
                            // Sau khi tên khớp, kiểm tra ID và trạng thái
                            if (animalDetail->getId() == currentId && animalDetail->getStatus() != 0) {
                                // Kiểm tra xem ID đã được nhập trước đó chưa
                                bool idAlreadyEntered = false;
                                for (unsigned int enteredId : petId) {
                                    if (enteredId == currentId) {
                                        idAlreadyEntered = true;
                                        break;
                                    }
                                }

                                if (!idAlreadyEntered) {
                                    isValidId = true;
                                }
                                break;
                            }
                        }
                    }

                    if (!isValidId) {
                        if (currentId != 0) {
                            ShowPopup(myFont, "ID does not match the pet name or status is not active!", 500, 100);
                        }
                    }


                    if (isValidId) {
                        petId.push_back(currentId);
                    }
                }
                if (petId.size() == totalItemsToBuy) {
                    // Cập nhật trạng thái của từng ID tương ứng
                    for (unsigned int id : petId) {
                        for (auto &animalDetail : animalDetails) {
                            if (animalDetail->getId() == id) {
                                animalDetail->setStatus();
                            }
                        }
                    }
                    SetWindowSize(widthWindow, heightWindow);
                    return;
                } else {
                    ShowPopup(myFont, "Not enough IDs entered!", 500, 100);
                }
            }
        }

        EndDrawing();
    }

    SetWindowSize(widthWindow, heightWindow);
}








void Screen::displayHistory(const Font &myFont, Texture &texture, vector<Customer *> Customers)
{
    // Nút thống kê doanh thu 
    Rectangle buttonRevenue = {(float)(widthWindow / 4 - 50), 100, 220, 40};
    DrawRectangleRounded(buttonRevenue, 0.6, 10, yellow);
    DrawTextEx(myFont, "Revenue Statistics", (Vector2){buttonRevenue.x + buttonRevenue.width / 2 - MeasureTextEx(myFont, "Revenue Statistics", 30, 2).x / 2, buttonRevenue.y + 10}, 30, 2, darkGreen);

    // Nút thông kê số lượng 
    Rectangle buttonQuantity = {(float)(3 * widthWindow / 4 - 50), 100, 220, 40};
    DrawRectangleRounded(buttonQuantity, 0.6, 10, yellow);
    DrawTextEx(myFont, "Quantity Statistics", (Vector2){buttonQuantity.x + buttonQuantity.width / 2 - MeasureTextEx(myFont, "Quantity Statistics", 30, 2).x / 2, buttonQuantity.y + 10}, 30, 2, darkGreen);

    // In thông tin khách hàng

    Customer::displayCustomers(myFont, texture, Customers);

    // Kiểm tra nhấn vào nút buttonRevenue
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttonRevenue)) {
        // Vẽ đồ thị
        Statistical::barChart();

    }
    // Kiểm tra nhấn vào nút buttonQuantity
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttonQuantity)) {
        // Vẽ đồ thị tròn
        Statistical::pieChart();
    }
}