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
