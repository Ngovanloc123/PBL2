#include <iostream>
#include <raylib.h>
#include "color.h"
#include "screen.h"
#include "LinkedList.h"
#include "dog.h"
#include "cat.h"

using namespace std;

int main() {
    Screen screen;
    Dogs dogs;
    Cats cats;
    // Tải phông chữ tùy chỉnh
    Font myFont = LoadFont("font/NerkoOne-Regular.ttf");
    cout << "Open My shop..." << endl;

    //----------------------------------------------------------------
    LinkedList PetList = new Node;
    if (PetList == NULL) {
        cout << "Out of space!" << endl;
        return 0;
    }

    Position p = PetList;
    Pet pet("Bulldog", "England", 10, "Short", 3, 2000, 3);
    p = PetList->insert(pet, p);

    Pet pet2("Persian", "Iran", 15, "Long", 2, 1500, 2);
    p = PetList->insert(pet2, p);
    PetList->display();
    PetList->eraseByName("Persian");
    PetList->display();
    //----------------------------------------------------------------

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
