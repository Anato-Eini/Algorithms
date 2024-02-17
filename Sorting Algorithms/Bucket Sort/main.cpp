#include <iostream>
#include "Node.h"

void printVector(vector<int>& arr){
    for(int i: arr)
        cout << i << ' ';
    cout << '\n';
}

void bucketSort(vector<int>& arr){
    vector<vector<int>> buckets(10);
    vector<int> output;
    for(int i: arr)
        buckets[i % 10].push_back(i);
    for(vector<int> a: buckets)

}

int main(){
    vector<int> arr;
    int a, c;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the elements of the array: ";
    for(int b = 1; b <= a; b++){
        cin >> c;
        arr.push_back(c);
    }
    cout << "Original array: ";
    printVector(arr);
    bucketSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}