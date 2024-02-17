#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H

void printVector(const vector<int>& arr){
    for(const int& i: arr)
        cout << i << ' ';
    cout << '\n';
}

void bucketSort(vector<int>& arr){
    vector<vector<int>> buckets(10);
    vector<int> output;
    for(int i: arr)
        buckets[i % 10].push_back(i);
    for(vector<int>& bucket: buckets)
        if(!bucket.empty())
            quickSort(bucket, 0, (int)bucket.size());
    for(vector<int> & bucket: buckets)
        if(!bucket.empty())
            for(const int &element: bucket)
                output.push_back(element);

    arr = output;
}

#endif //ALGORITHMS_BUCKETSORT_H
