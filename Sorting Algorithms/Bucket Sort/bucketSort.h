#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H

void printVector(const vector<int>& arr){
    for(const int& i: arr)
        cout << i << ' ';
    cout << '\n';
}

int bucketNumber(const vector<int>& arr){
    int max = 0;
    for (const int &i: arr) {
        int num = i / INTERVAL;
        if(num > max)
            max = num;
    }
    return max + 1;
}

void bucketSort(vector<int>& arr){
    vector<RedBlackTree> buckets(bucketNumber(arr));
    vector<int> output;
    for(int & i: arr)
        buckets[i / INTERVAL].insert(i);
    for(RedBlackTree rbt: buckets)
        while (!rbt.isEmpty())
            output.push_back(rbt.minimumValue());
    arr = output;
}

#endif //ALGORITHMS_BUCKETSORT_H
