#include "LinkedList.h"
#include <algorithm>

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
    // Node<T>* current = header;
    // Node<T>* nextNode;
    // while (current != NULL) {
    //     nextNode = current->next;
    //     delete current;
    //     current = nextNode;
    // }
}

template <typename T>
int LinkedList<T>::sizeList()
{
    return size;
}

// template <typename T>
// void LinkedList<T>::reset()
// {
//     // Node<T>* current = header;
//     // Node<T>* nextNode;
//     // while (current != NULL) {
//     //     nextNode = current->next;
//     //     // delete current;
//     //     current = nextNode;
//     // }
//     header = NULL;
//     size = 0;
//     page = 1;
// }
template <typename T>
void LinkedList<T>::reset() {
    // Node<T>* current = header;
    // Node<T>* nextNode;
    // while (current != NULL) {
    //     nextNode = current->next;
    //     delete current;
    //     current = nextNode;
    // }
    header = NULL; // Đặt header về NULL để tránh con trỏ rác
    size = 0;
    page = 1;
}

template <typename T>
void LinkedList<T>::backUpInformation(vector<Item> &items)
{
    // Duyệt qua LinkList và lưu thông tin vào item
    Node<T>* current = header;
    while (current!= NULL) {
        string name = current->getData().first.getName();
        unsigned int quantity = current->getData().second;
        unsigned int price = current->getData().first.getPrice();
        Item item(name, quantity, price);
        items.push_back(item);
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::updateQuantity(LinkedList<pair<T, unsigned int>> purchaseList) {
    Node<T>* currentInventory = header; // Con trỏ đến danh sách bán hàng (inventory)
    Node<pair<T, unsigned int>>* currentPurchase = purchaseList.getHead(); // Con trỏ đến danh sách mua hàng

    while (currentPurchase != NULL) {
        // So sánh tên theo thứ tự alphabet (không cần kiểm tra tồn tại do đảm bảo luôn khớp)
        if (strcmp(currentInventory->getData().getName(), currentPurchase->getData().first.getName()) == 0) {
            // Cập nhật số lượng
            currentInventory->getData().setQuantity(
                currentInventory->getData().getQuantity() - currentPurchase->getData().second
            );

            cout << "Updated " << currentInventory->getData().getName()
                      << ": Remaining quantity = " << currentInventory->getData().getQuantity() << "\n";

            // Di chuyển cả hai con trỏ
            currentInventory = currentInventory->next;
            currentPurchase = currentPurchase->getNext();
        } else {
            // Di chuyển con trỏ inventory để khớp tên
            currentInventory = currentInventory->next;
        }
    }
}


template <typename T>
Node<T> *LinkedList<T>::getHead()
{
    return header;
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
bool LinkedList<T>::insertCart(T value)
{
    Node<T>* newNode = new Node<T>(value);
    if (header == NULL) {  // Nếu danh sách rỗng
        header = newNode;
        size++;
        return true;
    }

    Node<T>* current = header;
    Node<T>* previous = NULL;

    while (current != NULL && current->data.first.getName() < newNode->data.first.getName()) {
        previous = current;
        current = current->next;
    }

    if(current != NULL && strcmp(current->data.first.getName(), newNode->data.first.getName()) == 0) {
        if(current->data.second + newNode->data.second > current->data.first.getQuantity()) {
            delete newNode;
            return false;
        }
        else {
            current->data.second += newNode->data.second;
            delete newNode;
            return true;
        }
        
    }

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
    return true;
}

template <typename T>
void LinkedList<T>::erase(Node<T>* node)
{
    // if (node == NULL) {  // Kiểm tra nếu node là NULL
    //     cout << "Error: Node to be deleted is null." << endl;
    //     return;
    // }

    // if (header == NULL) {  // Nếu danh sách đang rỗng
    //     cerr << "Error: Cannot delete from an empty list." << endl;
    //     return;
    // }

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

    // cerr << "Error: Node not found in the list." << endl;  // Nếu không tìm thấy node
}



template <typename T>
void LinkedList<T>::displayImages(const Font &myFont, Texture &texture, vector<char*> attributes)
{
    Node<T>* current = header;
    int i = 0;
    int startIdx = (page - 1) * 6; // Chỉ số bắt đầu của trang
    int endIdx = page * 6;         // Chỉ số kết thúc của trang (không bao gồm)

    while (current != NULL) {
        // Lấy các thuộc tính của đối tượng hiện tại
        vector<char*> animalAttributes = current->data.getAttributes();

        // Kiểm tra các thuộc tính không rỗng và khớp với từng thuộc tính trong vector attributes
        bool matches1 = (strcmp(attributes[0], "") == 0 || (strcmp(animalAttributes[0], attributes[0]) == 0));
        bool matches2 = (strcmp(attributes[1], "") == 0 || (strcmp(animalAttributes[1], attributes[1]) == 0));
        bool matches3 = (strcmp(attributes[2], "") == 0 || (strcmp(animalAttributes[2], attributes[2]) == 0));
        bool matches4 = (strcmp(attributes[3], "") == 0 || (strcmp(animalAttributes[3], attributes[3]) == 0));
        // Kiểm tra tìm kiếm
        string lowerStr1 = string(animalAttributes[4]);
        string lowerStr2 = string(attributes[4]);
        transform(lowerStr1.begin(), lowerStr1.end(), lowerStr1.begin(), ::tolower);
        transform(lowerStr2.begin(), lowerStr2.end(), lowerStr2.begin(), ::tolower);
        bool matches5 = (strcmp(attributes[4], "") == 0 || lowerStr1.find(lowerStr2) != string::npos);

        // Chỉ cần thỏa mãn các thuộc tính không rỗng
        if (matches1 && matches2 && matches3 && matches4 && matches5) {
            if (startIdx <= i && i < endIdx) {
                // Tính toán vị trí cột (0, 1, 2) và dòng (0, 1)
                int column = i % 3;
                int row = (i / 3) % 2;
                current->data.DisplayImage(myFont, texture, column, row);
            }
            i++;
        }
        current = current->next;
    }
}


template <typename T>
void LinkedList<T>::displayCart(const Font &myFont, Texture &texture, int quantity)
{
    Node<T>* current = header;
    int startIdx = (page - 1) * 8;
    int endIdx = page * 8 - 1;
    // int i = 0;

    while (current) {
        if (quantity >= startIdx && quantity <= endIdx) {
            int row = (quantity / 4) % 2; // Xác định hàng
            int col = quantity % 4;       // Xác định cột
            current->getData().first.DisplayItemFromCart(myFont, texture, row, col, current->getData().second);
        }
        current = current->next;
        quantity++;
    }
}

template <typename T>
long long LinkedList<T>::total()
{
    long long Subtotal = 0;
    Node<T>* current = header;

    while (current) {
        Subtotal += current->getData().second * current->getData().first.getSellingPrice();
        current = current->next;
    }
    return Subtotal;
}

template <typename T>
Node<T>* LinkedList<T>::GetNodeFromAnimal(const Vector2 &index, vector<char*> attributes)
{
    Node<T>* current = header;
    int sizeImage = 240;

    int startIdx = (page - 1) * 6; // Chỉ số bắt đầu của trang
    int endIdx = page * 6;         // Chỉ số kết thúc của trang (không bao gồm)

    int i = 0;
    while (current != NULL) {
        // Lấy các thuộc tính của đối tượng hiện tại
        vector<char*> animalAttributes = current->data.getAttributes();

        // Kiểm tra các thuộc tính không rỗng và khớp với từng thuộc tính trong vector attributes
        bool matches1 = (strcmp(attributes[0], "") == 0 || (strcmp(animalAttributes[0], attributes[0]) == 0));
        bool matches2 = (strcmp(attributes[1], "") == 0 || (strcmp(animalAttributes[1], attributes[1]) == 0));
        bool matches3 = (strcmp(attributes[2], "") == 0 || (strcmp(animalAttributes[2], attributes[2]) == 0));
        bool matches4 = (strcmp(attributes[3], "") == 0 || (strcmp(animalAttributes[3], attributes[3]) == 0));
        // Kiểm tra tìm kiếm
        string lowerStr1 = string(animalAttributes[4]);
        string lowerStr2 = string(attributes[4]);
        transform(lowerStr1.begin(), lowerStr1.end(), lowerStr1.begin(), ::tolower);
        transform(lowerStr2.begin(), lowerStr2.end(), lowerStr2.begin(), ::tolower);
        bool matches5 = (strcmp(attributes[4], "") == 0 || lowerStr1.find(lowerStr2) != string::npos);

        // Chỉ cần thỏa mãn các thuộc tính không rỗng
        if (matches1 && matches2 && matches3 && matches4 && matches5) {
            if (startIdx <= i && i < endIdx) {
                int gridX = i % 3; // 3 hình trên một dòng
                int gridY = (i / 3) % 2; // 2 dòng trên mỗi trang
                int posX = gridX * 248 + 8 + 100; // Khoảng cách giữa các cột
                int posY = gridY * 270 + 128 + 8; // Khoảng cách giữa các dòng
                Rectangle nodeArea = {(float)posX, (float)posY, (float)sizeImage, (float)(sizeImage + 20)};
                
                if (CheckCollisionPointRec(index, nodeArea)) {
                    return current;
                }
            }
            i++;
        }
        current = current->next;
    }
    return NULL;
}


template <typename T>
Node<T> *LinkedList<T>::GetNodeFromCart(const Vector2 &index, int quantity)
{
    Node<T>* current = header;
    int sizeImage = 140;

    int i = quantity;
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
void LinkedList<T>::deleteNodeInCart(const Vector2 &index, int quantity)
{
    Node<T>* current = header;
    int sizeImage = 40;
    int i = quantity;
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
    return size / 6 + (size % 6 > 0) + 1;
}

template <typename T>
void LinkedList<T>::setPage(int page)
{
    if(page >= 1 && page <= getPageMax())
        this->page = page;
}
