#include "LinkedList.h"

Node::~Node()
{
    Node* current = this;
    Node* nextNode = nullptr;
    delete data;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

LinkedList Node::createList()
{
    LinkedList header = new Node();
    header->next = nullptr;
    return header;
}

Position Node::insert(Pet pet, Position p)
{
    if(p == nullptr) return nullptr;
    Position newNode = new Node();
    newNode->data = pet;
    newNode->next = p->next;
    p->next = newNode;
    return newNode;
}

void Node::erase(Position p)
{
    if(p == nullptr || p->next == nullptr) return;
    Position tmp =  p->next;
    p->next = tmp->next;
    delete tmp;
}

void Node::display()
{
    Position current = next;
    while(current != nullptr) {
        current->data.display();
        current = current->next;
    }
}
