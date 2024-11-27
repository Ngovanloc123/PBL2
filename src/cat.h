#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

#include <raylib.h>
#include "animal.h"
#include "LinkedList.h"



class Cat : public Animal {
private:
    // Màu lông: one color, multicolor
    const char *coatColor;   
    // Mức độ phổ biến: widespread, medium, rare
    const char *popularity;    
    // Mức độ rụng lông: little, medium, much
    const char *sheddingLevel;    
    // Vẻ bề ngoài: noble, lovely, unique
    const char *appearance;
public:
    Cat(){};
    Cat(vector<string> inforNewCat);
    Cat(const char *name, const char *imageCat, const char *originOfCat, unsigned int averageAge, const char *furType, unsigned int numberOfCat, unsigned int sellingPrice, 
        unsigned int size, const char *coatColor, const char *popularity, const char *sheddingLevel, const char *appearance);
    Cat(const Cat& cat);
    virtual ~Cat();
    string GetType() const { return "Cat"; }
    const char *getCoatColor() const;
    const char *getPopularity() const;
    const char *getSheddingLevel() const;
    const char *getAppearance() const;

    vector<char*> getAttributes();
    vector<string> getAllAttributes();
    // Đọc file
    static void initializeCatList(LinkedList<Cat>& catList) {
        // Mở file để đọc nội dung hiện tại
        ifstream ifs("DB/cat.txt");
        
        // Kiểm tra file đã mở thành công hay chưa
        if (!ifs) {
            cerr << "Error: file not opened." << endl;
            return;
        }
        
        // Đọc từng chuỗi ngăn cách bởi dấu phẩy
        string line;
        Cat cat;

        while (getline(ifs, line)) {
            vector<string> tokens;
            string token;

            // Tạo một stringstream từ chuỗi đầu vào
            stringstream ss(line);

            // Đọc từng chuỗi ngăn cách bởi dấu phẩy
            while (getline(ss, token, ',')) {
                tokens.push_back(token);  // Thêm chuỗi vào vector
            }
            // Tạo đối tượng Cat
            cat = Cat(strdup(tokens[0].c_str()), strdup(tokens[1].c_str()), strdup(tokens[2].c_str()), stoi(tokens[3]), strdup(tokens[4].c_str()), stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7]), strdup(tokens[8].c_str()), strdup(tokens[9].c_str()), strdup(tokens[10].c_str()), strdup(tokens[11].c_str()));
            // Thêm đối tượng Cat vào danh sách
            catList.insert(cat);
            // cout << Cat.imageAnimal << endl;
        }

        // Đóng file sau khi đọc xong
        ifs.close();
    }
    void DisplayImage(const Font &myFont, Texture &texture, int gridX = 0, int gridY = 0);
    void displayInformation(const Font &myFont, Texture &texture, unsigned int &purQuant);
};

