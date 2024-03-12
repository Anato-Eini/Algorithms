#include "LinkedList.h"

void LinkedList::insertNum(int num) {
    Node* curr = head->next;
    while(curr != tail && curr->value < num) {
        curr = curr->next;
    }
    addBetween(curr->prev, curr, num);
    size++;
}

void LinkedList::addBetween(Node *prev, Node *next, int num) {
    prev->next = next->prev = new Node{num, prev, next};
}

void LinkedList::removeBetween(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

int LinkedList::removeHead() {
    int removedElement = head->next->value;
    removeBetween(head->next);
    size--;
    return removedElement;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}




