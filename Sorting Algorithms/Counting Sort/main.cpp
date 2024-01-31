#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& array){
    for(int i: array)
        cout << i << ' ';
    cout << '\n';
}

int maxElement(const vector<int>& array){
    int max = array[0];
    for(int i = 1; i < array.size(); i++)
        if(array[i] > max)
            max = array[i];
    return max;
}

void countingSort(vector<int>& array){
    int max = maxElement(array);
    vector<int> countArray(max + 1, 0);
    vector<int> duplicateArray(array.size());

    for(int i: array)
        countArray[i]++;
    for(int i = 1; i < max + 1; i++)
        countArray[i] += countArray[i - 1];
    for(int i = array.size() - 1; i >= 0; i--)
        duplicateArray[--countArray[array[i]]] = array[i];

    array = duplicateArray;
}

int main() {
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
    countingSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}
