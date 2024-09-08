#pragma once

class Node;
typedef class Node *LinkedList;
typedef class Node *Position;

class Node {
    Pet *data;
    Node *next;
public:
    ~Node();
    LinkedList createList();
    Position insert(Pet pet, Position p);
    void erase(Position p);
    void display();
};