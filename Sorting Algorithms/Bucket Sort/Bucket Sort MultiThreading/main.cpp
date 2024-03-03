#include <iostream>
#include <chrono>
#include <sstream>
#include <fstream>
#define INTERVAL 100000000
using namespace std;
#include "bucketSort.h"
int main(){
    /*int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for(int & i: array)
        cin >> i;

    cout << "Original array: ";
    for(int i: array)
        cout << i << " ";
    */
    ifstream inputFile(R"(I:TestFiles\10-10-7.txt)");
    if(!inputFile.is_open()){
        cerr << "File not opened";
        return 1;
    }
    vector<int> array;
    string input;
    while(getline(inputFile, input)){
        istringstream ss(input);
        string token;
        while(ss >> token)
            array.push_back(stoi(token));
    }
    
    int threads;
    cout << "Enter the number of threads: ";
    cin >> threads;
    auto start = chrono::high_resolution_clock::now();
    bucketSort(array, array.size(), threads);
    auto end = chrono::high_resolution_clock::now();
    cout << "Milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start);
/*
    cout << "\nSorted array: ";
    for(int i: array)
        cout << i << " ";*/
    return 0;
}