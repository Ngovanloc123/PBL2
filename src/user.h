#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "person.h"
#include "admin.h"
#include "FileManage.h"

#define ull unsigned long long

using namespace std;

class User : virtual public Person {
    public:
        User() = default;
        User(string name, string username, string password, string email, string phone, string village, string town, string province, string country);
        User(const User& user);
        ~User() = default;
        void resetPassword();
        void changeInformation(string name, string phone, string village, string town, string province, string country);
        void registerUser(const string& filename, string name, string username, string password, string email, string phone, string village, string town, string province, string country);
        bool loginUser(const string& filename, string username, string password) override;
        void logoutUser() override;
        friend class Admin;
};
