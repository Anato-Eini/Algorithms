#include <iostream>
#include <vector>
using namespace std;
int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void radixSortLSD(vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        for (int i : arr)
            count[(i / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = arr.size() - 1; i >= 0; i--)
            output[--count[(arr[i] / exp) % 10]] = arr[i];
        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
}
void printVector(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}
int main() {
    vector<int> arr;
    int a, c;
    cout << "Enter the size of the array: ";
    cin >> a;
    for(int b = 1; b <= a; b++){
        cout << "Enter element " << b << ": ";
        cin >> c;
        arr.push_back(c);
    }
    cout << "Original array: ";
    printVector(arr);
    radixSortLSD(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}
