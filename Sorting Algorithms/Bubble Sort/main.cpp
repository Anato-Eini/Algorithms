#include <iostream>

using namespace std;

void bubbleSort(int array[], int size){
    for(int i = 0; i < size; i++)
        for(int j = 1; j < size - i; j++)
            if(array[j - 1] > array[j]){
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
}
int main(){
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++)
        cin >> array[i];
    bubbleSort(array, size);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
        cout << array[i] << ' ';
    return 0;
}
