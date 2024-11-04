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
    LinkedList<Dog> cartDog;
    Dog::initializeDogList(dogList);
    
    cout << dogList.sizeList() << endl;
    //----------------------------------------------------------------

    Texture texture;
    Node<Dog>* NodeDog;
    bool clickedButtonPet = false;

    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(PINK);
        // Background
        screen.backGround();

        // Thanh điều hướng
        screen.navigationMenu(myFont, texture, clickedButtonPet);

        // Màn hình Intro
        if(screen.currentScreen == HOME) {
            screen.DrawHome(myFont);
        }

        // Màn hình lựa chọn chó
        if(screen.currentScreen == imagesDog) {
            // Hình ảnh chó
            dogList.displayImage(myFont, texture);
            // Nút trở về
            screen.DrawHeadingAnimal(myFont, dogList);
            // Lấy node từ mouseClick 
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
            if(NodeDog->getData().isAddToCart()) cartDog.insert(NodeDog->getData());
            cout << cartDog.sizeList() << endl;

            screen.HeadingInfor(myFont);
        }
        if (screen.currentScreen == detailCat) {
            // Thông tin

            screen.HeadingInfor(myFont);
        }

        // Thông tin shop
        if(screen.currentScreen == INTRO) {
            // Show thông tin
        }

        // Thông tin liên lạc
        if(screen.currentScreen == CONTACT) {
            // Show thông tin liên lạc
        }

        // Thông tin Shopping cart
        if(screen.currentScreen == shoppingCart) {
            // Show thông tin Shopping cart
            cartDog.displayImage(myFont, texture);
        }
        EndDrawing();
    }
    UnloadFont(myFont);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
