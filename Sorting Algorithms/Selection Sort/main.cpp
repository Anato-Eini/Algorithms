#include <iostream>
using namespace std;
void selectionSort(int array[], int size){
    for(int i = 0; i < size - 1; i++) {
        int smallest = i;
        for(int j = i + 1; j < size; j++)
            if(array[j] < array[smallest])
                smallest = j;
        if(smallest != i){
            int temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
        }
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
    selectionSort(array, size);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++)
        cout << array[i] << ' ';
    return 0;
}