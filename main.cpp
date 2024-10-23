#include <iostream>
#include <raylib.h>
// #include "color.h"
#include "screen.h"
// #include "LinkedList.cpp"  
#include "dog.h"
// #include "cat.h"

using namespace std;

int main() {
    Screen screen;
    // Dog dog;
    // Cats cats;
    // Tải phông chữ tùy chỉnh
    Font myFont = LoadFont("font/NerkoOne-Regular.ttf");
    cout << "Open My shop..." << endl;

    //----------------------------------------------------------------
    LinkedList<Dog> dogList;
    Dog::initializePetList(dogList);
    
    cout << dogList.sizeList() << endl;
    //----------------------------------------------------------------

    Texture texture;
    Node<Dog>* NodeDog;

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
        if(screen.currentScreen == imagesDog) {
            // Hình ảnh chó
            dogList.displayImage(myFont, texture);
            // Nút trở về
            screen.DrawHeadingAnimal(myFont, dogList);
            screen.HandleMouseClick(dogList, NodeDog);
        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == imagesCat) {
            // Hình ảnh mèo
            // ListCat.display(myFont, texture);
            // Nút trở về
            screen.DrawHeadingAnimal(myFont, dogList);
            
        }

        if (screen.currentScreen == detailDog) {
            // Thông tin
            NodeDog->getData().displayInformation(myFont, texture);
            screen.DrawHeading(myFont);
        }
        if (screen.currentScreen == detailCat) {
            // Thông tin
        }
        EndDrawing();
    }
    UnloadFont(myFont);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
