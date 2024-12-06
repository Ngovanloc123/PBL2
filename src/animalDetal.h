#pragma once

#include <string>
#include <raylib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


class AnimalDetail {
private:
    static unsigned int next_id;
    unsigned int id;
    string name;
    string weight;
    string sex;
    bool status;
public:
    AnimalDetail() {};
    AnimalDetail(string name, string weight, string sex);
    AnimalDetail(vector<string> inforNewAnimalDetail);
    AnimalDetail(unsigned int id, string name, string weight, string sex, bool status);
    static void initializeNextIdFromFile(const string& filename);
    // static void 
    unsigned int getId();
    string getName();
    string getWeight();
    string getSex();
    bool getStatus();
    void setStatus();
};