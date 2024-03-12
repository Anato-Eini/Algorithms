#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "Node.h"
#include <iostream>
class LinkedList {
    Node* head;
    int size;
public:
    LinkedList(): size(0), head(new Node{0, nullptr}) {}
    [[nodiscard]] bool isEmpty() const;
    void insertNum(int);
    int removeHead();
};


#endif //ALGORITHMS_LINKEDLIST_H
