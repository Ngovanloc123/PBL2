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
    LinkedList<Dog> PetList;
    Dog dog("Akita", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    PetList.insert(dog);
    Dog dog2("B", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    PetList.insert(dog2);
    // Dog dog3("U", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    // PetList.insert(dog3);
    // Dog dog4("R", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    // PetList.insert(dog4);
    // Dog dog5("M", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    // PetList.insert(dog5);
    // Dog dog6("E", "image/Dogs/Akita.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    // PetList.insert(dog6);
    // Dog dog7("H", "image/Dogs/Basenji.png", "Nam phi", 10, "Short", 3, 2000, 3, "O nha", "Hight", "YES");
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    // PetList.insert(dog7);
    cout << PetList.sizeList() << endl;
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
            PetList.displayImage(myFont, texture);
            // Nút trở về
            screen.DrawText_DrawTextLabel_Image(myFont, PetList);
            screen.HandleMouseClick(PetList, NodeDog);
        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == imagesCat) {
            // Hình ảnh mèo
            // ListCat.display(myFont, texture);
            // Nút trở về
            screen.DrawText_DrawTextLabel_Image(myFont, PetList);
            
        }

        if (screen.currentScreen == detailDog) {
            // Thông tin
            NodeDog->getData().displayInformation(myFont, texture);
            screen.DrawText_DrawTextLabel_Detail(myFont);
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
