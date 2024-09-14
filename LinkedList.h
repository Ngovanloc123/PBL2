#pragma once
#include"pet.h"

class Node;
typedef class Node *LinkedList;
typedef class Node *Position;

class Node {
    Pet data;
    Node *next;
public: 
    Node();
    // ~Node();
    Position insert(const Pet &pet, Position p);
    void erase(Position p);
    void eraseByName(string name);

    void display();
};