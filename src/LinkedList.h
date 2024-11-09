#pragma once
#include <raylib.h>
#include <exception>
#include <cstring>
#include <iostream>

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
    void insert(T value);
    void erase(Node<T> *node);
    int getPage();
    int getPageMax();
    void setPage(int page);
    void displayImages(const Font &myFont, Texture &texture);
    void displayCart(const Font &myFont, Texture &texture);
    Node<T>* GetNodeFromAnimal(const Vector2 &index);
    Node<T>* GetNodeFromCart(const Vector2 &index);
    void deleteNodeFromCart(const Vector2 &index);
};

