#include <iostream>
#include <raylib.h>
// #include "color.h"
#include "screen.h"
// #include "LinkedList.cpp"  
#include "dog.h"
#include "cat.h"

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

    LinkedList<Cat> catList;
    LinkedList<Cat> cartCat;
    Cat::initializeCatList(catList);

    
    // cout << dogList.sizeList() << endl;
    //----------------------------------------------------------------

    Texture texture;
    Node<Dog>* NodeDog;
    Node<Cat>* NodeCat;

    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(PINK);
        // Background
        screen.backGround();

        // Thanh điều hướng
        screen.navigationMenu(myFont, texture);

        // Màn hình Intro
        if(screen.currentScreen == HOME) {
            screen.DrawHome(myFont);
        }

        // Màn hình lựa chọn chó
        if(screen.currentScreen == imagesDog) {
            // Hình ảnh chó
            dogList.displayImages(myFont, texture);
            // Các nút tại image Dog
            screen.DrawHeadingAnimal(myFont, dogList);
            // Lấy nodeDog
            screen.getNode(dogList, NodeDog);
        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == imagesCat) {
            // Hình ảnh mèo
            catList.displayImages(myFont, texture);
            // Các nút tại image Cat
            screen.DrawHeadingAnimal(myFont, catList);
            // Lấy nodeCat
            screen.getNode(catList, NodeCat);
        }

        if (screen.currentScreen == detailDog) {
            // Thông tin
            NodeDog->getData().displayInformation(myFont, texture);
            if(NodeDog->getData().isAddToCart()) cartDog.insert(NodeDog->getData());
            // cout << cartDog.sizeList() << endl;

            screen.Heading(myFont);
        }
        if (screen.currentScreen == detailCat) {
            // Thông tin
            NodeCat->getData().displayInformation(myFont, texture);
            if(NodeCat->getData().isAddToCart()) cartCat.insert(NodeCat->getData());

            screen.Heading(myFont);
        }

        // Thông tin shop
        if(screen.currentScreen == INTRO) {
            // Show thông tin
            screen.Heading(myFont);
        }

        // Thông tin liên lạc
        if(screen.currentScreen == CONTACT) {
            // Show thông tin liên lạc
            screen.Heading(myFont);
        }

        // Thông tin Shopping cart
        if(screen.currentScreen == shoppingCart) {
            // Show thông tin Shopping cart
            cartDog.displayCart(myFont, texture);
            screen.Heading(myFont);
            // Các nút tại image Dog
            screen.DrawHeadingAnimal(myFont, cartDog);
            // Lấy node từ mouseClick 
            screen.getNode(cartDog, NodeDog);
            screen.deleteNode(cartDog);
        }
        EndDrawing();
    }
    UnloadFont(myFont);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
