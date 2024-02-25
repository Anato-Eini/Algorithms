#include <iostream>
#include "RedBlackTree.h"
#include <vector>
#include <cmath>
#define INTERVAL 10
using namespace std;
#include "bucketSort.h"


int main(){
    vector<int> arr;
    int size, element;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for(int b = 1; b <= size; b++)
        cin >> element, arr.push_back(element);

    cout << "Original array: ";
    printVector(arr);
    bucketSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}