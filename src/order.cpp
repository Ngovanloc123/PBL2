#include "order.h"

unsigned int Order::currentOrderId = 1;
Item::Item(string name, unsigned int quantity, unsigned int price)
{
    this->name = name;
    this->quantity = quantity;
    this->price = price*quantity;
}

long long Item::getTotalPrice(){
    return this->price;
}

string Item::getName(){
    return this->name;
}

unsigned int Item::getQuantity(){
    return this->quantity;
}

Order::Order(unsigned int order_id, unsigned int customer_id, unsigned int totalAmount, string day, string month, string year, vector<Item> Items)
{
    this->order_id = order_id;
    this->customer_id = customer_id;
    this->totalAmount = totalAmount;
    this->day = day;
    this->month = month;
    this->year = year;
    this->Items = Items;
}

Order::Order(unsigned int customer_id, unsigned int totalAmount, string day, string month, string year, vector<Item> Items)
{
    this->order_id = Order::currentOrderId++;
    this->customer_id = customer_id;
    this->totalAmount = totalAmount;
    this->day = day;
    this->month = month;
    this->year = year;
    this->Items = Items;
}

long long Order::calculateTotalAmount(){
    totalAmount = 0.0;
    for(auto& item : Items){
        totalAmount += item.getTotalPrice();
    }
    return totalAmount;
}

unsigned int Order::getOrderId(){
    return this->order_id;
}

unsigned int Order::getCustomerId(){
    return this->customer_id;
}

string Order::getOrderDetails(){
    stringstream ss;
    ss << this->order_id << "," << this->customer_id << "," << this->totalAmount << "," << this->day << "," << this->month << "," << this->year << endl;
    for(auto& item : Items){
        ss << item.getName() << "," << item.getQuantity() << "," << item.getTotalPrice() << endl;
    }
    ss << "----------" << endl;
    return ss.str();
}

string Order::getOrderDay(){
    return this->day;
}

string Order::getOrderMonth(){
    return this->month;
}

string Order::getOrderYear(){
    return this->year;
}

vector<Item> Order::getItems(){
    return this->Items;
}
void Order::generalInvoice(Order& order){
    string filename = "DB/invoice." + to_string(order.getOrderId()) + ".txt";
    ofstream file(filename);
    if(!file){
        cout << "Error: " << filename << endl;
        return;
    }
    file << "Invoice for: " << order.getOrderId() << endl;
    file << "----------" << endl;
    file << "User id: " << order.getOrderId() << endl;
    file << "Date: " <<order.getOrderDay() << "-" << order.getOrderMonth() << "-" << order.getOrderYear() << endl;
    file << "Total amount: " << order.calculateTotalAmount() << endl;
    vector<Item> items = order.getItems();
    for(auto& item : items){
        file <<"Name:" << item.getName() << "Quantity:" << item.getQuantity() << "- " << item.getTotalPrice() << endl;
    }
    file << "Goodbye and See You Again!" << endl;
    file << "Address: 54 Nguyen Luong Bang - Hoa Khanh Bac - Lien Chieu - Da Nang" << endl;
}

void Order::initializeOrderIdFromFile(const string& filename){
    ifstream file(filename);
    if(!file){
        cout << "Error" << endl;
        return;
    }
    int max_id = 0;
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        int order_id;
        if(iss >> order_id){
            max_id = max(max_id, order_id);
        }
    }
    currentOrderId = max_id + 1;
    cout << "Order Id: " << currentOrderId << endl;
    file.close();
}

void Order::saveToFile(const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    file << this->getOrderDetails();
    file.close();
}
