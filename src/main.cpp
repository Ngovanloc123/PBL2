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
// #include "order.cpp"
#include "customer.h"
#include "FileManage.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    Screen screen;
    // Tải phông chữ tùy chỉnh
    Font myFont = LoadFont("font/NerkoOne-Regular.ttf");
    cout << "Open My shop..." << endl;

    //----------------------------------------------------------------
    LinkedList<Dog> dogList;
    Dog::initializeDogList(dogList);


    LinkedList<Cat> catList;
    Cat::initializeCatList(catList);

    Cart<Dog> cartDog;
    Cart<Cat> cartCat;

    // Thông in người mua hàng
    Customer::initializeNextIdFromFile("DB/customer.txt");
    vector<Customer*> Customers = FileManager::loadFromFile("DB/customer.txt");
    //----------------------------------------------------------------
    //Thông tin đơn hàng
    Order::initializeOrderIdFromFile("DB/order.txt");
    Texture texture;
    Node<Dog>* NodeDog;
    Node<Cat>* NodeCat;
    unsigned int purQuant = 1;
    // Trạng thái pet
    vector<char*> attributesDog(5, "");
    vector<char*> attributesCat(5, "");
    long long Subtotal = 0;
    unsigned int customer_id = 0;

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
        //----------------------------------------------------------------
            // Thêm chó
            Rectangle addPetButton = {450, 70, 60, 50};
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), addPetButton)) {
                vector<string> InforNewDog;
                screen.inputInforNewItem(myFont, texture, InforNewDog, 1);
                Dog newDog(InforNewDog);
                dogList.insert(newDog); 
            }
            
        //----------------------------------------------------------------
            // Lấy nodeDog
            screen.getNode(dogList, NodeDog, attributesDog, purQuant);
        }

        // Màn hình lựa chọn mèo
        if(screen.currentScreen == imagesCat) {
            // Hình ảnh mèo
            catList.displayImages(myFont, texture, attributesCat);
            // Các nút tại image Cat
            screen.HeadingAnimal(myFont, catList, attributesCat);
        //----------------------------------------------------------------
            // Thêm mèo
            Rectangle addPetButton = {450, 70, 60, 50};
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), addPetButton)) {
                vector<string> InforNewCat;
                screen.inputInforNewItem(myFont, texture, InforNewCat, 2);
                Cat newCat(InforNewCat);
                catList.insert(newCat);
            }
        //----------------------------------------------------------------

            // Lấy nodeCat
            screen.getNode(catList, NodeCat, attributesCat, purQuant);
        }

        if (screen.currentScreen == detailDog) {
            // Thông tin
            NodeDog->getData().displayInformation(myFont, texture, purQuant);
            if (NodeDog && cartDog.isAddToCart()) {
                cartDog.addToCart(myFont, make_pair(NodeDog->getData(), purQuant), screen);
                purQuant = 1;
            }
            // Xóa nút
            Rectangle deleteButton = {(356 + 550), 500, 150, 60};
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), deleteButton)) {
                if(screen.ShowPopup(myFont, "Are you sure delete?", 600, 100)) {
                    screen.currentScreen = imagesDog;
                    dogList.erase(NodeDog);
                }
            }
            // Thay đổi thông tin chó
            Rectangle editButton = {(356 + 350), 500, 150, 60};
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), editButton)) {
                vector<string> InforDog = NodeDog->getData().getAllAttributes();
                screen.inputInforNewItem(myFont, texture, InforDog, 1);
                screen.currentScreen = imagesDog;
                dogList.erase(NodeDog);
                // Đưa thông tin chó mới cập nhật
                Dog newDog(InforDog);
                dogList.insert(newDog);
                NodeDog = new Node<Dog>(newDog);
                screen.currentScreen = detailDog;
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
            // Xóa nút
            Rectangle deleteButton = {(float)(356 + 550), 500, 150, 60};
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), deleteButton)) {
                if(screen.ShowPopup(myFont, "Are you sure delete?", 600, 100)) {
                    screen.currentScreen = imagesCat;
                    catList.erase(NodeCat);
                }
            }
            // Thay đổi thông tin mèo
            Rectangle editButton = {(float)(356 + 350), 500, 150, 60};
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), editButton)) {
                vector<string> InforCat = NodeCat->getData().getAllAttributes();
                screen.inputInforNewItem(myFont, texture, InforCat, 2);
                screen.currentScreen = imagesCat;
                catList.erase(NodeCat);
                // Đưa thông tin mèo mới cập nhật
                Cat newCat(InforCat);
                catList.insert(newCat);
                NodeCat = new Node<Cat>(newCat);
                screen.currentScreen = detailCat;
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
            cartCat.viewCart(myFont, texture, cartDog.getCartItems().sizeList()); // In tiếp
            // In tiêu đề
            screen.Heading(myFont);
            // Lấy node từ mouseClick
            cartDog.getItem(NodeDog, screen);
            cartCat.getItem(NodeCat, screen, cartDog.getCartItems().sizeList());
            // Xóa item
            cartDog.remove();
            cartCat.remove(cartDog.getCartItems().sizeList());
        }

        // Tính tổng tiền thanh toán
        Subtotal = cartDog.calculateTotal() + cartCat.calculateTotal();
        
        // Mua hàng
        Rectangle buttonSubtotal = {(float(GetScreenWidth() - 220)), 20, 200, 50};
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttonSubtotal)) {
            if(Subtotal > 0) {
                bool check = false;
                vector<string> InforNewCustomer;
                screen.inputInforNewItem(myFont, texture, InforNewCustomer, 3);
                for(auto& customer : Customers) {
                    if(customer->checkCustomer(InforNewCustomer[1])) {
                        customer->updateInformation(InforNewCustomer);
                        customer->setPurchaseQuantity();
                        customer_id = customer->getId();
                        check = true;
                        break;
                    }
                }
                if(!check) {
                    Customer *newCustomer = new Customer(InforNewCustomer);
                    Customers.push_back(newCustomer);
                    customer_id = newCustomer->getId();
                }
                FileManager::saveToFile("DB/customer.txt", Customers);
                //--------------------------------------------
                // Đưa thông tin vào order
                time_t now = time(nullptr);
                tm* ltm = localtime(&now);
                string day = to_string(ltm->tm_mday);
                string month = to_string(1 + ltm->tm_mon);
                string year = to_string(1900 + ltm->tm_year);

                vector<Item> Items;
                cartDog.getCartItems().backUpInformation(Items);
                cartCat.getCartItems().backUpInformation(Items);

                Order newOrder(customer_id, Subtotal, day, month, year, Items);
                newOrder.saveToFileOrder("DB/order.txt");
                newOrder.saveToFileSales("DB/sales.txt");
                newOrder.generalInvoice(newOrder);
                //--------------------------------------------
                // Cập nhật số lượng
                dogList.updateQuantity(cartDog.getCartItems());
                catList.updateQuantity(cartCat.getCartItems());
                // reset giỏ hàng và trừ đi số lượng đã mua hàng
                cartDog.resetCart();
                cartCat.resetCart();
            } else {
                screen.ShowPopup(myFont, "Cart is empty!", 600, 100);
            }
        }

        EndDrawing();
    }
    // delete cartDog;
    UnloadFont(myFont);
    UnloadTexture(texture);
    CloseWindow();

    // Update lại thông tin Pet
    FileManager::saveToFileDog("DB/dog.txt", dogList);
    FileManager::saveToFileCat("DB/cat.txt", catList);
    return 0;
}
