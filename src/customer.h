#pragma once

#include <string>
#include <raylib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


class Customer {
private:
    static unsigned int next_id;
    unsigned int id;
    string name;
    string phoneNumber;
    string address;
    unsigned int purchaseQuantity;
public:
    Customer() {};
    Customer(string name, string phoneNumber, string address, unsigned int purchaseQuantity);
    Customer(vector<string> inforNewCustomer);
    Customer(unsigned int id, string name, string phoneNumber, string address, unsigned int purchaseQuantity);
    static void initializeNextIdFromFile(const string& filename);
    unsigned int getId();
    string getName();
    string getPhoneNumber();
    string getAddress();
    unsigned int getPurchaseQuantity();
    void setPurchaseQuantity();
    bool checkCustomer(string phomeNumber);
    void updateName(string name);
    void updateAddress(string address);
    void updateInformation(vector<string> inforNewCustomer);
    void displayCustomer(const Font &myFont, Texture &texture, int gridX, int gridY);
    static void displayCustomers(const Font &myFont, Texture &texture, vector<Customer *> Customers);

};