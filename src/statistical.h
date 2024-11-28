#pragma once

#include <raylib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

class Bar {
private:
    int month;
    int price;
    int quantity;
    string name;
public:
    Bar(int month, int price, int quantity, string name) {
        this->month = month;
        this->price = price;
        this->quantity = quantity;
        this->name = name;
    }

    int getMonth() const {
        return month;
    }

    int getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    string getName() const {
        return name;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setPrice(int price) {
        this->price = price;
    }
    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
    void setName(string name) {
        this->name = name;
    }
    static void insertionSort(vector<Bar>& bars);
    static Color GetUniqueColor(int index, int totalParts);
    static void mergeSmallBars(vector<Bar>& bars, float threshold = 5.0f);
    static vector<string> WrapText(const string& text, int maxWidth, int fontSize);
    
};

class Statistical {
public:
    static void pieChart();
    static void barChart();
};

