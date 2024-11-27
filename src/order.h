#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Item {
private:
    string name;
    unsigned int quantity;
    unsigned int price;
public:
    Item() {};
    Item(string name, unsigned int quantity, unsigned int price);
    long long getTotalPrice();
    string getName();
    unsigned int getQuantity();
};

class Order {
private:
    static unsigned int currentOrderId;
    unsigned int order_id;
    unsigned int customer_id;
    unsigned int totalAmount;
    string day;
    string month;
    string year;
    vector<Item> Items; 
public:
    Order() {};
    Order(unsigned int order_id, unsigned int customer_id,unsigned int totalAmount, string day, string month, string year, vector<Item> Items = {});
    Order(unsigned int customer_id, unsigned int totalAmount, string day, string month, string year, vector<Item> Items = {});
    long long calculateTotalAmount();
    unsigned int getOrderId();
    unsigned int getCustomerId();
    vector<Item> getItems();
    string getOrderDetails();
    string getOrderDay();
    string getOrderMonth();
    string getOrderYear();
    void generalInvoice(Order& orders);
    static void initializeOrderIdFromFile(const string& filename);
    void saveToFile(const string& filename);
};