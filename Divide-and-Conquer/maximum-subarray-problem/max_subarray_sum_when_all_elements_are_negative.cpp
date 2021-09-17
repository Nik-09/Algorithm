// This program finds the maximum subarray sum when all the elements are negative.

#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int a[n];

    // This solution is very small because we know beforehand that all the elements
    // in the array are negative integers.

    cout<<"Enter only negative numbers\n\n ";
    for (int i = 0; i < n; i++)
        cin>>a[i];

    // Return single element with largest negative value.
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    cout<<"Maximum sum of subarray is : "<<max<<"\n";    
}