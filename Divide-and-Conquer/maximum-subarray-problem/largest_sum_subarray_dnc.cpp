// This program finds maximum subarray problem by divide and conquer strategy.

#include<iostream>
#include<vector>
#define INT_MAX 999999
using namespace std;

int max_crossing_subarray_sum(vector<int> v, int l, int m, int r);
int max_subarray (vector<int> v, int l, int r);

int main(void) {
    int n, a;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin>>a;
        v.push_back(a);
    }

    int max_subarray_sum = max_subarray(v, 0, n-1);

    cout<<max_subarray_sum<<"\n";
}

int max_subarray (vector<int> v, int l, int r) {

    // Checking for base case.
    if (l == r)
        return v[l];
        
    int m = l + (r - l) / 2;

    int left_sum = max_subarray(v, l, m);
    int right_sum = max_subarray(v, m+1, r);
    int cross_sum = max_crossing_subarray_sum(v, l, m, r);


    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return right_sum;
    else    
        return cross_sum;
}

int max_crossing_subarray_sum(vector<int> v, int l, int m, int r) {

    int left_max_sum = -INT_MAX;
    int right_max_sum = -INT_MAX;
    int sum = 0;
    for (int i = m; i >= 0; i--) {
        sum += v[i];
        if (sum >= left_max_sum)
            left_max_sum = sum;
    }

    sum = 0;
    for (int i = m+1; i <= r; i++) {
        sum += v[i];
        if (sum >= right_max_sum)
            right_max_sum = sum;
    }

    return (left_max_sum + right_max_sum);
}