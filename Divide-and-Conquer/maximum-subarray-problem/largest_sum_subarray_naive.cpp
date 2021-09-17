#include<iostream>
#define INT_MAX 999999
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];

    int max = -INT_MAX, sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum > max)
                max = sum;
        }
        cout<<i<<" "<<sum<<" "<<max<<endl;
    }

    cout<<"MAXIMUM SUBARRAY SUM = "<<max<<"\n";
}