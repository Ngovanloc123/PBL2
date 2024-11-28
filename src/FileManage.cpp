#include"FileManage.h"

using namespace std;

vector<Customer*> FileManager::loadFromFile(const string& filename) {
    vector<Customer*> Customers;
    ifstream file(filename);
    
    // Kiểm tra xem file có mở thành công không
    if (!file.is_open()) {
        cerr << "Cannot open file " << filename << endl;
        return Customers;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        unsigned int id;
        string name, phoneNumber, address;
        unsigned int purchaseQuantity;
        getline(ss, line, ',');
        id = stoi(line);
        getline(ss, name, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, address, ',');
        getline(ss, line, ',');
        purchaseQuantity = stoi(line);
        Customer* customer = new Customer(id, name, phoneNumber, address, purchaseQuantity);
        if (customer != NULL) {
            cout << "Create: " << id << " " << name << " " << phoneNumber << " " << address << " " << purchaseQuantity << endl;
        Customers.push_back(customer);
        }
    }
    file.close();
    return Customers;
}


void FileManager::saveToFile(const string& filename, const vector<Customer*>& Customers) {
    ofstream file(filename);
    if(!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    for(Customer* Customer : Customers) {
        file << Customer->getId() << "," << Customer->getName() << "," << Customer->getPhoneNumber() << "," << Customer->getAddress() << "," << Customer->getPurchaseQuantity() << endl;
    }
    file.close();
}

void FileManager::saveToFileDog(const string &filename, LinkedList<Dog> dogList)
{
    ofstream file(filename);
    if(!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    for (Node<Dog>* current = dogList.getHead(); current != nullptr; current = current->getNext()) {
        file << current->getData().getName() << "," << current->getData().getImageAnimal() << "," << current->getData().getOrigin() << "," << current->getData().getAverageAge() << ","
        << current->getData().getFurType() << "," << current->getData().getQuantity() << "," << current->getData().getPrice() << "," << current->getData().getSize() << ","
        << current->getData().getPurposeOfRaising() << "," << current->getData().getLevelOfTraining() << "," << current->getData().getNeedForExercise() << endl;
    }
    file.close();
}

void FileManager::saveToFileCat(const string &filename, LinkedList<Cat> catList)
{
    ofstream file(filename);
    if(!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    for (Node<Cat>* current = catList.getHead(); current!= nullptr; current = current->getNext()) {
        file << current->getData().getName() << "," << current->getData().getImageAnimal() << "," << current->getData().getOrigin() << "," << current->getData().getAverageAge() << ","
        << current->getData().getFurType() << "," << current->getData().getQuantity() << "," << current->getData().getPrice() << "," << current->getData().getSize() << ","
        << current->getData().getCoatColor() << "," << current->getData().getPopularity() << "," << current->getData().getSheddingLevel() << "," << current->getData().getAppearance() << endl;
    }
    file.close();
}

// vector<Product*> FileManager::loadProductFromFile(const string& filename) {
//     vector<Product*> products;
//     ifstream file(filename);
//     if(!file.is_open()) {
//         cerr << "Khong the mo file " << filename << endl;
//         return products;
//     }
//     string line;
//     while(getline(file, line)){
//         stringstream ss(line);
//         int product_id, product_quantity;
//         double product_price;
//         string product_type, product_breed;
//         getline(ss, line, ',');
//         product_id = stoi(line);
//         getline(ss, product_type, ',');
//         getline(ss, product_breed, ',');
//         getline(ss, line, ',');
//         product_quantity = stoi(line);
//         getline(ss, line, ',');
//         product_price = stod(line);
//         Product* product = new Product(product_id, product_type.c_str(), product_breed.c_str(), product_quantity, product_price);
//         products.push_back(product);
//     }
//     file.close();
//     return products;
// }

// void FileManager::saveProductToFile(const string& filename, const vector<Product*>& products) {
//     ofstream file(filename);
//     if(!file) {
//         cerr << "Khong the mo file " << filename << endl;
//         return;
//     }
//     for(Product* product : products) {
//         file << product->getId() <<","<<product->getType() <<","<<product->getBreed() <<","<<product->getQuantity() <<","<<product->getPrice() << endl;
//     }
//     file.close();
// }
