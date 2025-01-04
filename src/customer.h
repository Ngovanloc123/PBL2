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
    unsigned int purchaseQuantity; // Số lượng mua hàng
public:
    Customer() {};
    Customer(string name, string phoneNumber, string address, unsigned int purchaseQuantity);
    Customer(vector<string> inforNewCustomer);
    Customer(unsigned int id, string name, string phoneNumber, string address, unsigned int purchaseQuantity);
    // Xác định id tiếp theo để gán cho người mới mua lần đầu
    static void initializeNextIdFromFile(const string& filename);

    // ----------------------------------------------------------------

    // Lấy thông tin người dùng
    unsigned int getId();
    string getName();
    string getPhoneNumber();
    string getAddress();
    unsigned int getPurchaseQuantity();

    // ----------------------------------------------------------------

    // Cập nhật thông tin người dùng
    void setPurchaseQuantity();
    bool checkCustomer(string phomeNumber);
    void updateName(string name);
    void updateAddress(string address);
    void updateInformation(vector<string> inforNewCustomer);
    // ----------------------------------------------------------------
    
    // In thông tin người dùng
    void displayCustomer(const Font &myFont, Texture &texture, int gridX, int gridY);
    // In thông tin tất cả người dùng
    static void displayCustomers(const Font &myFont, Texture &texture, vector<Customer *> Customers);

};