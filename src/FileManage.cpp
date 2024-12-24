#include"FileManage.h"

using namespace std;

vector<Customer*> FileManager::loadCustomerFromFile(const string& filename) {
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

vector<AnimalDetail *> FileManager::loadAnimalDetailFromFile(const string &filename)
{
    vector<AnimalDetail *> animalDetails;
    ifstream file(filename);
    
    // Kiểm tra xem file có mở thành công không
    if (!file.is_open()) {
        cerr << "Cannot open file " << filename << endl;
        return animalDetails;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        unsigned int id;
        string name, weight, sex;
        bool status;
        getline(ss, line, ',');
        id = stoi(line);
        getline(ss, name, ',');
        getline(ss, weight, ',');
        getline(ss, sex, ',');
        getline(ss, line, ',');
        status = stoi(line);
        AnimalDetail* animalDetail = new AnimalDetail(id, name, weight, sex, status);
        if (animalDetail!= NULL) {
            cout << "Create: " << id << " " << name << " " << weight << " " << sex << " " << status << endl;
            animalDetails.push_back(animalDetail);
        }
    }
    file.close();
    return animalDetails;

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

void FileManager::saveToFileAnimalDetail(const string &filename, vector<AnimalDetail *> &animalDetail)
{
    ofstream file(filename);
    if(!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    for(AnimalDetail* animalDetail : animalDetail) {
        file << animalDetail->getId() << "," << animalDetail->getName() << "," << animalDetail->getWeight() << "," << animalDetail->getSex() << "," << animalDetail->getStatus() << endl;
    }
    file.close();
}