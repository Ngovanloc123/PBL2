#include <iostream>
#include <vector>
#include <raylib.h>
#include <utility>
// #include "color.h"
#include "screen.h"
// #include "LinkedList.cpp"
#include "dog.h"
#include "cat.h"
#include "cart.cpp"

// #include "person.h"
// #include "admin.h"
// #include "user.h"
// #include "authorize.cpp"
// #include "FileManage.h"
#include <cstdlib>
#include <fstream>

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
    Dog::initializeDogList(dogList);

    // LinkedList<Dog> cartDog;

    LinkedList<Cat> catList;
    Cat::initializeCatList(catList);

    Cart<Dog> cartDog;
    Cart<Cat> cartCat;
    //----------------------------------------------------------------

    Texture texture;
    Node<Dog>* NodeDog;
    Node<Cat>* NodeCat;
    unsigned int purQuant = 1;
    // Trạng thái pet
    vector<char*> attributesDog(5, "");
    vector<char*> attributesCat(5, "");
    long long Subtotal = 0;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(PINK);
        
        // Background
        screen.backGround();

        // Thanh điều hướng
        screen.navigationMenu(myFont, texture, Subtotal);
        
        // Màn hình Intro
        if(screen.currentScreen == HOME) {
            screen.DrawHome(myFont);
        }

        // Màn hình lựa chọn chó
        if(screen.currentScreen == imagesDog) {
            // Hình ảnh chó
            dogList.displayImages(myFont, texture, attributesDog);
            // Các nút tại image Dog
            screen.HeadingAnimal(myFont, dogList, attributesDog);
            // Lấy nodeDog
            screen.getNode(dogList, NodeDog, attributesDog);
        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == imagesCat) {
            // Hình ảnh mèo
            catList.displayImages(myFont, texture, attributesCat);
            // Các nút tại image Cat
            screen.HeadingAnimal(myFont, catList, attributesCat);
            // Lấy nodeCat
            screen.getNode(catList, NodeCat, attributesCat);
        }

        if (screen.currentScreen == detailDog) {
            // Thông tin
            NodeDog->getData().displayInformation(myFont, texture, purQuant);
            if (NodeDog && cartDog.isAddToCart()) {
                cartDog.addToCart(myFont, make_pair(NodeDog->getData(), purQuant), screen);
                purQuant = 1;
            }


            screen.Heading(myFont);
        }
        if (screen.currentScreen == detailCat) {
            // Thông tin
            NodeCat->getData().displayInformation(myFont, texture, purQuant);
            if (NodeCat && cartCat.isAddToCart()) {
                cartCat.addToCart(myFont, make_pair(NodeCat->getData(), purQuant), screen);
                purQuant = 1;
            }

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
            cartDog.viewCart(myFont, texture);
            cartCat.viewCart(myFont, texture, cartDog.getCartItems().sizeList());
            // In tiêu đề
            screen.Heading(myFont);
            // Các nút tại image Dog
            // screen.HeadingAnimal(myFont, cartDog.getCartItems()); // tạo cái khác riêng cho cart
            // Lấy node từ mouseClick 
            cartDog.getItem(NodeDog, screen);// lõi ở đây
            cartDog.remove();
        }

        // Tính tổng tiền thanh toán
        Subtotal = cartDog.calculateTotal() + cartCat.calculateTotal();
        EndDrawing();
    }
    // delete cartDog;
    UnloadFont(myFont);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
