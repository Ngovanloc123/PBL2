#include "FileManage.h"
#include "admin.h"
#include "user.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Person* login(const string& username, const string& password) {
    Admin admin;
    User user;
    if (admin.loginUser("accounts.txt",username, password)) {
        cout << "Dang nhap thanh cong duoi vai tro Admin." << endl;
        cout << "Thong tin User: ";
        admin.viewInformation("");
        return new Admin(admin);
    } else if (user.loginUser("accounts.txt",username, password)) {
        cout << "Dang nhap thanh cong duoi vai tro User." << endl;
        cout << "Thong tin User: " << endl;
        user.viewInformation();
        user.changeUsername("hahaha");
        user.viewInformation();
        return new User(user);
    } else {
        cout << "Dang nhap that bai." << endl;
        return nullptr;
    }
}
