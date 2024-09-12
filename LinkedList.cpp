#include "LinkedList.h"

Node::Node()
{
    next = NULL;
}

// Node::~Node()
// {
    // cout << next << " ";
    // delete next;
    // while (next != NULL) {
    //     Node* temp = next;
    //     next = next->next;
    //     delete temp;
    // }
// }

Position Node::insert(const Pet &pet, Position p)
{
    if(p == NULL) return NULL;
    Position newNode = new Node;
    if (newNode == NULL) {
        cout << "Out of space!" << endl;
        return NULL;
    }
    newNode->data = pet;
    newNode->next = p->next;
    p->next = newNode;
    return newNode;
}

void Node::erase(Position p)
{
    if(p == NULL || p->next == NULL) return;
    Position tmp =  p->next;
    p->next = tmp->next;
    delete tmp;
}

void Node::eraseByName(string name)
{
    Position currentNode = this;
    Position nextNode = currentNode->next;
    
    while(nextNode != NULL) {
        if(nextNode->data.getName().compare(name) == 0) {
            currentNode->next = nextNode->next;
            delete nextNode;
            return;
        }
        currentNode = nextNode;
        nextNode = nextNode->next;
    }
}

void Node::display()
{
    Position current = next;
    while(current != NULL) {
        current->data.displayInformation();
        current = current->next;
    }
}
