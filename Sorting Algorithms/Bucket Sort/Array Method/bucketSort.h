#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H

void printArray(int array[], int size){
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << '\n';
}

int findMin(const int arr[], int n){
    int minimum = arr[0];
    for (int i = 0; i < n; ++i)
        if(arr[i] < minimum)
            minimum = arr[i];
    return minimum;
}

int findMax(const int arr[], int n){
    int maximum = arr[0];
    for (int i = 0; i < n; ++i)
        if(maximum < arr[i])
            maximum = arr[i];
    return maximum;
}

void bucketSort(int array[], int size){
    int out[size], minNum = findMin(array, size);
    if (minNum)

}

#endif //ALGORITHMS_BUCKETSORT_H
