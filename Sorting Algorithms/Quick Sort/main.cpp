#include <iostream>
using namespace std;

int partition(int array[], int left, int right){
    int pivot = array[right], low = left;

    for(int i = left; i <= right; i++)
        if(pivot > array[i])
            swap(array[i], array[low++]);

    swap(array[right], array[low]);
    return low;
}

void quickSort(int array[], int left, int right){
    if(left < right){
        int partitionIndex = partition(array, left, right);

        quickSort(array, left, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, right);
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

    quickSort(array, 0, size - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
        cout << array[i] << ' ';
    return 0;
}