#pragma once
#include <raylib.h>
// #include "screen.h"

template <typename T>
class LinkedList;  // Forward

template <typename T>
class Node {
private:
    T data;
    Node* next;

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
    ~LinkedList();
    int sizeList();
    void insert(T value);
    void erase(const char* name);
    int getPage();
    int getPageMax();
    void setPage(int page);
    void displayImage(const Font &myfont, Texture &texture);
    Node<T>* GetNodeFromClick(const Vector2 &index);
    
};

