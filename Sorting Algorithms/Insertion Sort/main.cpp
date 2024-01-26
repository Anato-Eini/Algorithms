#include <iostream>
using namespace std;
void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++)
        if(array[i - 1] > array[i]){
            int temp = array[i], j = i - 1;
            for(; j >= 0; j--) {
                if (array[j] > temp)
                    array[j + 1] = array[j];
                else break;
            }
            array[j + 1] = temp;
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
    insertionSort(array, size);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
        cout << array[i] << ' ';
    return 0;
}