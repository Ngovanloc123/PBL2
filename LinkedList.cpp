#include "LinkedList.h"
#include <iostream>
// #include "screen.h"
#include <cstring>

using namespace std;

template <typename T>
inline LinkedList<T>::LinkedList() : header(NULL)
{
    size = 0;
    page = 1;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = header;
    Node<T>* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
int LinkedList<T>::sizeList()
{
    return size;
}

template <typename T>
void LinkedList<T>::insert(T value)
{
    Node<T>* newNode = new Node<T>(value);
    if (header == nullptr) {  // Nếu danh sách rỗng
        header = newNode;
        size++;
        return;
    }

    // Insert theo tên
    Node<T>* current = header;
    Node<T>* previous = nullptr;

    while (current != nullptr && current->data.getName() < newNode->data.getName()) {
        previous = current;
        current = current->next;
    }

    if(current != nullptr && strcmp(current->data.getName(), newNode->data.getName()) == 0) return;

    // Nếu nút mới là nhỏ nhất (chèn vào đầu danh sách)
    if (previous == nullptr) {
        newNode->next = header;
        header = newNode;
    } else {
        // Chèn giữa hai nút
        newNode->next = current;
        previous->next = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::erase(const char* name) 
{   
    if (header == nullptr) {  // Nếu danh sách đang rỗng
        return;
    }

    Node<T>* current = header;
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        if (strcmp(current->data.getName(), name) == 0) {  // Nếu tên tìm thấy
            if (previous == nullptr) {  // Nút đang xét là nhỏ nhất
                header = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}


template <typename T>
void LinkedList<T>::displayImage(const Font &myFont, Texture &texture)
{
    Node<T>* current = header;
    int i = 0;
    while (current != nullptr) {
        if((page - 1) * 8 <= i && i <= page * 8 - 1)
            current->data.DisplayImage(myFont, texture, i % 4, (i / 4) % 2);
        current = current->next;
        i++;
    }
}

template <typename T>
Node<T> *LinkedList<T>::GetNodeFromClick(const Vector2 &index)
{
    Node<T>* current = header;
    int sizeImage = 240;

    int i = 0;
    while(current != nullptr ) {
        int gridX = i % 4;
        int gridY = (i / 4) % 2;
        int posX = gridX * 248 + 8 + 100;
        int posY = gridY * 270 + 128 + 8;
        Rectangle nodeArea = {(float)posX, (float)(posY), (float)sizeImage, (float)(sizeImage + 20)};
        if(CheckCollisionPointRec(index, nodeArea) && (page - 1)*8 <= i && i <= page * 8 - 1) {
            return current;
        }
        current = current->next;
        i++;
    }
    return nullptr;
}

template <typename T>
int LinkedList<T>::getPage()
{
    return page;
}

template <typename T>
int LinkedList<T>::getPageMax()
{
    return size / 8 + (size % 8 > 0);
}

template <typename T>
void LinkedList<T>::setPage(int page)
{
    if(page >= 1 && page <= getPageMax())
        this->page = page;
}
