#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

#include <raylib.h>
#include "animal.h"
#include "LinkedList.h"



class Dog : public Animal {
private:
    // Mục đích nuôi: Pet, Companion, Guard
    const char *purposeOfRaising;   
    // Mức độ huấn luyện: Kindergarten, Grade school, Junior High
    const char *levelOfTraining;    
    // Nhu cầu hoạt động:  High, Medium, Low
    const char *needForExercise;    
public:
    Dog(){};
    Dog(const char *name, const char *imageDog, const char *originOfDog, unsigned int averageAge, const char *furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, const char *purposeOfRaising, const char *levelOfTraining, const char *needForExercise);
    Dog(const Dog& dog);
    virtual ~Dog();
    string GetType() const { return "Dog"; }
    vector<char*> getAttributes();
    // Đọc file
    static void initializeDogList(LinkedList<Dog>& dogList) {
        // Mở file để đọc nội dung hiện tại
        ifstream ifs("DB/dog.txt");
        
        // Kiểm tra file đã mở thành công hay chưa
        if (!ifs) {
            cerr << "Error: file not opened." << endl;
            return;
        }
        
        // Đọc từng chuỗi ngăn cách bởi dấu phẩy
        string line;
        Dog dog;
        while (getline(ifs, line)) {
            vector<string> tokens;
            string token;

            // Tạo một stringstream từ chuỗi đầu vào
            stringstream ss(line);

            // Đọc từng chuỗi ngăn cách bởi dấu phẩy
            while (getline(ss, token, ',')) {
                tokens.push_back(token);  // Thêm chuỗi vào vector
            }
            // Tạo đối tượng Dog
            dog = Dog(strdup(tokens[0].c_str()), strdup(tokens[1].c_str()), strdup(tokens[2].c_str()), stoi(tokens[3]), strdup(tokens[4].c_str()), stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7]), strdup(tokens[8].c_str()), strdup(tokens[9].c_str()), strdup(tokens[10].c_str()));
            // Thêm đối tượng Dog vào danh sách
            dogList.insert(dog);
            // cout << dog.imageAnimal << endl;
        }

        // Đóng file sau khi đọc xong
        ifs.close();
    }
    void DisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
    void displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant);
};

