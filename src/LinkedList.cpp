#include "LinkedList.h"

// #include "screen.h"




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
    while (current != NULL) {
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
    if (header == NULL) {  // Nếu danh sách rỗng
        header = newNode;
        size++;
        return;
    }

    // Insert theo tên
    Node<T>* current = header;
    Node<T>* previous = NULL;

    while (current != NULL && current->data.getName() < newNode->data.getName()) {
        previous = current;
        current = current->next;
    }

    if(current != NULL && strcmp(current->data.getName(), newNode->data.getName()) == 0) return;

    // Nếu nút mới là nhỏ nhất (chèn vào đầu danh sách)
    if (previous == NULL) {
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
void LinkedList<T>::erase(Node<T>* node) 
{
    if (node == NULL) {  // Kiểm tra nếu node là NULL
        cerr << "Error: Node to be deleted is null." << endl;
        return;
    }

    if (header == NULL) {  // Nếu danh sách đang rỗng
        cerr << "Error: Cannot delete from an empty list." << endl;
        return;
    }

    Node<T>* current = header;
    Node<T>* previous = NULL;

    while (current != NULL) {
        if (current == node) {  // Nếu tìm thấy node cần xóa
            if (previous == NULL) {  // Node đang xét là node đầu tiên
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

    cerr << "Error: Node not found in the list." << endl;  // Nếu không tìm thấy node
}



template <typename T>
void LinkedList<T>::displayImages(const Font &myFont, Texture &texture)
{
    Node<T>* current = header;
    int i = 0;
    while (current != NULL) {
        if((page - 1) * 8 <= i && i <= page * 8 - 1) 
            current->data.DisplayImage(myFont, texture, i % 4, (i / 4) % 2);
        current = current->next;
        i++;
    }
}

template <typename T>
void LinkedList<T>::displayCart(const Font &myFont, Texture &texture)
{
    Node<T>* current = header;
    int i = 0;
    while (current != NULL) {
        if((page - 1) * 8 <= i && i <= page * 8 - 1) {
            current->data.DisplayItemFromCart(myFont, texture, (i / 4) % 2, (i % 4));
        }
        current = current->next;
        i++;
    }
}

template <typename T>
Node<T> *LinkedList<T>::GetNodeFromAnimal(const Vector2 &index)
{
    Node<T>* current = header;
    int sizeImage = 240;

    int i = 0;
    while(current != NULL ) {
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
    return NULL;
}

template <typename T>
Node<T> *LinkedList<T>::GetNodeFromCart(const Vector2 &index)
{
    Node<T>* current = header;
    int sizeImage = 140;

    int i = 0;
    while(current != NULL ) {
        int gridX = (i / 4) % 2;
        int gridY = (i % 4);

        float posX = gridX * (500 + 30) + 100;
        float posY = gridY * (sizeImage + 5) + 128;
        Rectangle nodeArea = {(float)posX, (float)(posY), (float)sizeImage, (float)(sizeImage )};
        if(CheckCollisionPointRec(index, nodeArea) && (page - 1)*8 <= i && i <= page * 8 - 1) {
            return current;
        }
        current = current->next;
        i++;
    }
    return NULL;
}

template <typename T>
void LinkedList<T>::deleteNodeFromCart(const Vector2 &index)
{
    Node<T>* current = header;
    int sizeImage = 40;
    int i = 0;
    while(current != NULL ) {
        int gridX = (i / 4) % 2;
        int gridY = (i % 4);

        float posX = gridX * (500 + 30) + 100;
        float posY = gridY * (140 + 5) + 128;
        Rectangle nodeArea = {(float)(posX + 300 + 140), (float)(posY + 140/2 - 40/2), (float)sizeImage, (float)(sizeImage)};
        if(CheckCollisionPointRec(index, nodeArea) && (page - 1)*8 <= i && i <= page * 8 - 1) {
            this->erase(current);
            return;
        }
        current = current->next;
        i++;
    }
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
