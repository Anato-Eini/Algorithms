#include "MSDRadixSort.h"
#include <cmath>

Node* MSDRadixSort::createNode() {
    Node* newNode = new Node;
    for(Node*& i : newNode->next)
        i = nullptr;
    return newNode;
}

void MSDRadixSort::insert(int num) {
    root->array.push_back(num);
}

int MSDRadixSort::maxDigit(){
    int max = 0;
    for(int i: root->array){
        int digit = (int)log10(i);
        if(digit > max)
            max = digit;
    }
    return max;
}

void MSDRadixSort::sortHelper(Node *node, int exponent, vector<int>& sortedArray) {
    if(exponent < 0)
        return;

    for(int i: node->array) {
        int index = i / exponent % 10;
        if(!node->next[index])
            node->next[index] = createNode();
        node->next[index]->array.push_back(i);
    }

    for(auto & i : node->next) {
        if(!i)
            continue;
        else if(i->array.size() > 1)
            sortHelper(i, exponent / 10, sortedArray);
        else
            sortedArray.push_back(i->array[0]);
    }
}

void MSDRadixSort::sort() {
    vector<int> sortedArray;
    sortHelper(root, (int)pow(10, maxDigit()), sortedArray);
    root->array = sortedArray;
}

void MSDRadixSort::print() {
    for(int i: root->array)
        cout << i << " ";
    cout << '\n';
}