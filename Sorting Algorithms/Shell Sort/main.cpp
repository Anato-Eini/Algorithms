#include <iostream>

using namespace std;

void shellSort(int array[], int size){
    for(int gap = size / 2; gap > 0; gap /= 2)
        for(int i = gap; i < size; i += gap)
            if(array[i] < array[i - gap]) {
                int j, temp = array[i];
                for (j = i - gap; j >= 0; j -= gap) {
                    if(array[j] > temp)
                        array[j + gap] = array[j];
                    else break;
                }
                array[j + gap] = temp;
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

    shellSort(array, size);

    cout << "Sorted array: ";
    for(int i: array)
        cout << i << ' ';

    return 0;
}
