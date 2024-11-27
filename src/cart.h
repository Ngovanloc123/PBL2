#pragma once

// #include "cat.h"
#include <raylib.h>
#include "screen.h"
// #include "dog.h"
#include "screen.h"
#include "LinkedList.h"
// #include <vector>
// #include <iostream>
// #include <memory>
// #include "FileManage.h"
// using namespace std;

template <typename T>
class Cart {
    LinkedList<pair<T, unsigned int>> cartItems;
public:
    Cart() {}  
    ~Cart() {}
    LinkedList<pair<T, unsigned int>>& getCartItems();
    void resetCart();
    bool isAddToCart();
    void addToCart (const Font &myFont, pair<T, unsigned int> item, Screen &screen);
    void remove(int quantity = 0);
    void viewCart(const Font &myFont, Texture &texture, int quantity = 0);
    void getItem(Node<T>* &item, Screen &screen, int quantity = 0);
    long long calculateTotal();
    // void updateQuantity(int productId, int quantity);
    // double getTotalPrice() const; // tinh tong tien cua cart item
};
