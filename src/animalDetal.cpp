#include "animalDetal.h"

unsigned int AnimalDetail::next_id = 1;

AnimalDetail::AnimalDetail(string name, string weight, string sex)
{
    this->id = next_id++;
    this->name = name;
    this->weight = weight;
    this->sex = sex;
    this->status = true;
}

AnimalDetail::AnimalDetail(vector<string> inforNewAnimalDetail)
{
    this->id = next_id++;
    this->name = inforNewAnimalDetail[0];
    this->weight = inforNewAnimalDetail[1];
    this->sex = inforNewAnimalDetail[2];
    this->status = stoi(inforNewAnimalDetail[3]);
}

AnimalDetail::AnimalDetail(unsigned int id, string name, string weight, string sex, bool status)
{
    this->id = id;
    this->name = name;
    this->weight = weight;
    this->sex = sex;
    this->status = status;
}

void AnimalDetail::initializeNextIdFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    unsigned int max_id = 0;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        unsigned int user_id;
        if (iss >> user_id) {
            max_id = max(max_id, user_id);
        }
    }
    next_id = max_id + 1;
}

unsigned int AnimalDetail::getId()
{
    return id;
}

string AnimalDetail::getName()
{
    return name;
}

string AnimalDetail::getWeight()
{
    return weight;
}

string AnimalDetail::getSex()
{
    return sex;
}

bool AnimalDetail::getStatus()
{
    return status;
}

void AnimalDetail::setStatus()
{
    status =!status;
}
