#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H
#include <cmath>
#include <thread>
#include <cassert>
#include "heapSort.h"

typedef long long int ll;
int findMax(const int array[], ll size){
    int maximum = array[0];
    for (int i = 1; i < size; ++i)
        if(maximum < array[i])
            maximum = array[i];
    return maximum;
}

int findMin(const int array[], ll size){
    int minimum = array[0];
    for(int i = 1; i < size; i++)
        if(minimum > array[i])
            minimum = array[i];
    return minimum;
}

void worker(vector<deque<int>> &arr, ll start, ll end) {
    for(; start <= end; start++)
        if (!arr[start].empty())
            heapSort(arr[start], arr[start].size());
}

void bucketSort(int array[], ll size, int & threads) {
    thread thrd[threads];

    int minimum = findMin(array, size);
    if (minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] -= minimum;

    ll maximum = findMax(array, size), range = (ll) ceil((double) maximum / INTERVAL) + 1, index = 0;

    vector <deque<int>> buckets(range);
    for (ll i = 0; i < size; ++i)
        buckets[array[i] / INTERVAL].push_back(array[i]);

    ll interval = range / threads;
    for(int i = 0; i < threads; i++)
        thrd[i] = thread(worker, ref(buckets), interval * i + 1,
                           i == threads - 1 ? buckets.size() - 1 : interval * (i + 1));

    for(int i = 0; i < threads; i++)
        if (thrd[i].joinable())
            thrd[i].join();

    for(deque<int> d: buckets){
        while(!d.empty()){
            array[index++] = d.front();
            d.pop_front();
        }
    }
    if(minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] += minimum;
}


#endif //ALGORITHMS_BUCKETSORT_H