#include <iostream>
#include <raylib.h>
#include <dogLibrary.h>
#include <catLibrary.h>
#include <color.h>
#include <screen.h>

using namespace std;

int main() {
    Screen screen;
    Dogs dogs;
    Cats cats;
    // Tải phông chữ tùy chỉnh
    Font myFont = LoadFont("font/NerkoOne-Regular.ttf");
    cout << "Open My shop..." << endl;
    // screen.initWindow();

    // Screens currentScreen = MENU;

    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(PINK);
        // Background
        screen.backGround();
        // Màn hình MENU
        if(screen.currentScreen == MENU) {
            screen.DrawMenu(myFont);
        }
        // Màn hình lựa chọn chó
        if(screen.currentScreen == informationDog) {
            // Hình ảnh chó
            dogs.DrawDogs(myFont);
            // Nút trở về
            screen.DrawDogInfoScreen(myFont);

        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == informationCat) {
            // Hình ảnh mèo
            // cats.DrawCats(myFont);
            // Nút trở về
            screen.DrawCatInfoScreen(myFont);
        }

        if (screen.currentScreen == detail) {
            // Thông tin
        }
        EndDrawing();
    }
    UnloadFont(myFont);
    CloseWindow();
    return 0;
}
