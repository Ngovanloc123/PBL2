// #include <iostream>
// #include <variant>
// #include <string>

// using namespace std;

// // Định nghĩa lớp Node với một kiểu dữ liệu template T
// template <typename T>
// struct Node {
//     T data;
//     Node* next;

//     // Constructor khởi tạo node với dữ liệu
//     Node(T d) : data(d), next(nullptr) {}
// };

// // Định nghĩa lớp LinkedList với một kiểu dữ liệu template là std::variant chứa nhiều kiểu dữ liệu
// template <typename... Types>
// class LinkedList {
// private:
//     using VariantType = variant<Types...>;
//     Node<VariantType>* head;

// public:
//     LinkedList() : head(nullptr) {}

//     // Hàm thêm node vào cuối danh sách
//     void addNode(const VariantType& data) {
//         Node<VariantType>* newNode = new Node<VariantType>(data);
//         if (head == nullptr) {
//             head = newNode;
//         } else {
//             Node<VariantType>* temp = head;
//             while (temp->next != nullptr) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }

//     // Hàm hiển thị danh sách
//     void display() const {
//         Node<VariantType>* temp = head;
//         while (temp != nullptr) {
//             visit([](auto&& arg) { cout << arg << " "; }, temp->data);
//             temp = temp->next;
//         }
//         // cout << "-> nullptr" << endl;
//     }

//     // Destructor để giải phóng bộ nhớ
//     ~LinkedList() {
//         Node<VariantType>* current = head;
//         while (current != nullptr) {
//             Node<VariantType>* nextNode = current->next;
//             delete current;
//             current = nextNode;
//         }
//     }
// };

// int main() {
//     pair<int, int> p;
//     // Tạo linked list có thể chứa int, double và string
//     LinkedList<int, double, string> list;

//     // Thêm các node với dữ liệu khác nhau
//     list.addNode(42);            // int
//     list.addNode(3.14);          // double
//     list.addNode("Hello World"); // string
//     list.addNode("Hello World"); // string

//     // Hiển thị danh sách
//     list.display();

//     return 0;
// }
