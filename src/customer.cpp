#include "customer.h"

unsigned int Customer::next_id = 1;

Customer::Customer(string name, string phoneNumber, string address, unsigned int purchaseQuantity)
{
    this->id = next_id++;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->purchaseQuantity = purchaseQuantity;
}

Customer::Customer(vector<string> inforNewCustomer)
{
    this->id = next_id++;
    this->name = inforNewCustomer[0];
    this->phoneNumber = inforNewCustomer[1];
    this->address = inforNewCustomer[2];
    this->purchaseQuantity = 1;
}

Customer::Customer(unsigned int id, string name, string phoneNumber, string address, unsigned int purchaseQuantity)
{
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->purchaseQuantity = purchaseQuantity;
}

void Customer::initializeNextIdFromFile(const string &filename)
{
    ifstream file(filename);
    if(!file){
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    unsigned int max_id = 0;
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        unsigned int user_id;
        if(iss >> user_id){
            max_id = max(max_id, user_id);
        }
    }
    next_id = max_id + 1; //dam bao id khong bi trung
    file.close();
}

unsigned int Customer::getId()
{
    return id;
}

string Customer::getName()
{
    return name;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

string Customer::getAddress()
{
    return address;
}

unsigned int Customer::getPurchaseQuantity()
{
    return purchaseQuantity;
}

void Customer::setPurchaseQuantity()
{
    purchaseQuantity++;
}

bool Customer::checkCustomer(string phomeNumber)
{
    return this->phoneNumber == phomeNumber;
}

void Customer::updateName(string name)
{
    this->name = name;
}

void Customer::updateAddress(string address)
{
    this->address = address;
}

void Customer::updateInformation(vector<string> inforNewCustomer)
{
    updateName(inforNewCustomer[0]);
    updateAddress(inforNewCustomer[2]);
}

void Customer::displayCustomer(const Font &myFont, Texture &texture, int gridX, int gridY)
{
    int cellHeight = 40; // Chiều cao mỗi dòng
    int cellWidth[5] = {50, 150, 120, 150, 20}; // Độ rộng của từng cột

    // Hiển thị từng ô trong hàng
    DrawTextEx(myFont, to_string(id).c_str(), { (float)gridX, (float)gridY }, cellHeight * 0.6f, 2, BLACK);
    DrawTextEx(myFont, name.c_str(), { (float)(gridX + cellWidth[0]), (float)gridY }, cellHeight * 0.6f, 2, BLACK);
    DrawTextEx(myFont, phoneNumber.c_str(), { (float)(gridX + cellWidth[0] + cellWidth[1]), (float)gridY }, cellHeight * 0.6f, 2, BLACK);
    DrawTextEx(myFont, address.c_str(), { (float)(gridX + cellWidth[0] + cellWidth[1] + cellWidth[2]), (float)gridY }, cellHeight * 0.6f, 2, BLACK);
    DrawTextEx(myFont, to_string(purchaseQuantity).c_str(), { (float)(gridX + cellWidth[0] + cellWidth[1] + cellWidth[2] + cellWidth[3]), (float)gridY }, cellHeight * 0.6f, 2, BLACK);
}


void Customer::displayCustomers(const Font &myFont, Texture &texture, vector<Customer *> Customers)
{
    int startX = 50, startY = 160; // Tọa độ bắt đầu
    int cellHeight = 40;           // Chiều cao mỗi dòng
    int cellWidth[5] = {50, 150, 120, 150, 20}; // Độ rộng các cột

    // Vẽ tiêu đề cột 1
    DrawTextEx(myFont, "ID", { (float)startX, (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Name", { (float)(startX + cellWidth[0]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Phone", { (float)(startX + cellWidth[0] + cellWidth[1]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Address", { (float)(startX + cellWidth[0] + cellWidth[1] + cellWidth[2]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "PQ", { (float)(startX + cellWidth[0] + cellWidth[1] + cellWidth[2] + cellWidth[3]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    // Vẽ tiêu đê cột 2
    DrawTextEx(myFont, "ID", { (float)(startX + 620), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Name", { (float)(startX + 620 + cellWidth[0]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Phone", { (float)(startX + 620 + cellWidth[0] + cellWidth[1]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "Address", { (float)(startX + 620 + cellWidth[0] + cellWidth[1] + cellWidth[2]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);
    DrawTextEx(myFont, "PQ", { (float)(startX + 620 + cellWidth[0] + cellWidth[1] + cellWidth[2] + cellWidth[3]), (float)startY }, cellHeight * 0.6f, 2, DARKGRAY);

    // Vẽ danh sách khách hàng
    int i = 1;
    int currentY = startY + cellHeight; // Dòng đầu tiên của danh sách
    for (Customer *customer : Customers)
    {
        if(i == 13) {
            startX += 620;
            currentY = startY + cellHeight;
        }
        customer->displayCustomer(myFont, texture, startX, currentY);
        currentY += cellHeight; // Xuống dòng
        i++;
    }
}

