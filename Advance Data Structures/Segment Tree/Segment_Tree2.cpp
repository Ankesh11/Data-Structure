#include <bits/stdc++.h>
using namespace std;
//Range Minimum Query using Segment Tree
int construct_st_util(int arr[], int beg, int end, int *st, int si){
    if(beg==end){
        st[si] = arr[beg];
        return st[si];
    }
    int mid = (beg+end)/2;
    st[si] = min(construct_st_util(arr, beg, mid, st, 2*si+1),
                construct_st_util(arr, mid+1, end, st, 2*si+2));
    return st[si];
}
int *construct_st(int arr[], int n){
    int h = log2((double)n);
    int size = 2*pow(2,h)-1;
    int *st = new int[size];
    construct_st_util(arr, 0, n-1, st, 0);
    return st;
}
int RMQ_util(int *st, int beg, int end, int l, int r, int si){
    if(l<=beg && r>=end)
        return st[si];
    else if(l>end || r<beg)
        return INT_MAX;
    int mid = (beg+end)/2;
    return min(RMQ_util(st, beg, mid, l, r, 2*si+1),
                RMQ_util(st, mid+1, end, l, r, 2*si+2));
}
int RMQ(int *st, int n, int l, int r){
    if(l<0 || l>n-1 || r<0 || r>n-1)
        return INT_MAX;
    return RMQ_util(st, 0, n-1, l, r, 0);
}
int main(){
    int arr[] = {2, 5, 1, 4, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = construct_st(arr, n);
    cout<<RMQ(st, n, 0,5)<<endl;
    cout<<RMQ(st, n, 3, 5)<<endl;
    return 0;
}
