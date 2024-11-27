#include "cart.h"

template <typename T>
LinkedList<pair<T, unsigned int>> &Cart<T>::getCartItems()
{
    return cartItems;
}

template <typename T>
bool Cart<T>::isAddToCart()
{
    Rectangle AddToCart =  {(float)((float)(248 + 8 + 100 + 100)), 500, 200, 60};
    if(CheckCollisionPointRec(GetMousePosition(), AddToCart) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        return true;
    }
    return false;
}

template <typename T>
void Cart<T>::addToCart(const Font &myFont, pair<T, unsigned int> item, Screen &screen)
{   
    if(!cartItems.insertCart(item)) {
        screen.ShowPopup(myFont, "The selected quantity exceeds your purchase limit!", 600, 100);
    }
}

template <typename T>
void Cart<T>::remove(int quantity)
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 index = GetMousePosition();
        cartItems.deleteNodeInCart(index, quantity);
    }
}

template <typename T>
void Cart<T>::viewCart(const Font &myFont, Texture &texture, int quantity) {
    cartItems.displayCart(myFont, texture, quantity);
}

template <typename T>
void Cart<T>::getItem(Node<T> *&item, Screen &screen, int quantity)
{

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 index = GetMousePosition();

        Node<pair<T, unsigned int>> *item_q = cartItems.GetNodeFromCart(index, quantity);

        // Nếu NodeAnimal hợp lệ, kiểm tra loại đối tượng
        if (item_q != NULL) {
            // Đưa dữ liệu T của item_q vào Node item
            item = new Node<T>(item_q->getData().first);
            string type = item->getData().GetType();

            // Chuyển màn hình dựa trên loại động vật
            if (type == "Dog") {
                screen.beforeScreen = screen.currentScreen;
                screen.currentScreen = detailDog;
            } else if (type == "Cat") {
                screen.beforeScreen = screen.currentScreen;
                screen.currentScreen = detailCat;
            }
        }
    }
}

template <typename T>
long long Cart<T>::calculateTotal()
{
    return cartItems.total();
}
