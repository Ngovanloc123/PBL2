#pragma once
#include <raylib.h>
#include <exception>
#include <cstring>
#include <iostream>
#include <vector>

// #include "screen.h"

using namespace std;

template <typename T>
class LinkedList;  // Forward

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

    friend class LinkedList<T>;

public:
    Node(T value) : data(value), next(nullptr) {}
    T getData() { return data;}
};

template <typename T>
class LinkedList  {
private:
    Node<T>* header; 
    int size;
    int page; // Trang in hình ảnh hiện tại
public: 
    LinkedList();
    virtual ~LinkedList();
    int sizeList();
    Node<T>* getHead();
    void insert(T value);
    // Pair
    bool insertCart(T value);

    void erase(Node<T> *node);
    int getPage();
    int getPageMax();
    void setPage(int page);
    void displayImages(const Font &myFont, Texture &texture, vector<char*> attributes);
    void displayCart(const Font &myFont, Texture &texture, int quantity = 0);
    long long total();
    Node<T>* GetNodeFromAnimal(const Vector2 &index, vector<char*> attributes);
    Node<T>* GetNodeFromCart(const Vector2 &index, int quantity = 0);
    void deleteNodeInCart(const Vector2 &index, int quantity = 0);
    // void listManagement(const Font &myFont, Texture &texture);
};

