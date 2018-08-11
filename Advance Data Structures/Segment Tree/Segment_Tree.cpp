#include <bits/stdc++.h>
using namespace std;
void update_util(int *st, int beg, int end, int val, int i, int si){
    if(i<beg || i>end)
        return;
    st[si] = st[si]+val;
    if(beg!=end){
        int mid = (beg+end)/2;
        update_util(st, beg, mid, val, i, si*2+1);
        update_util(st, mid+1, end, val, i, si*2+2);
    }
}
void update(int arr[], int n, int *st, int new_val, int i){
    if(i<0 || i>n-1)
        return;
    int diff = new_val - arr[i];
    arr[i] = new_val;
    update_util(st, 0, n-1, diff, i, 0);
}
int get_sum_util(int *st, int beg, int end, int l, int r, int index){
    if(l<=beg && r>=end)
        return st[index];
    if(l>end || r<beg)
        return 0;
    int mid = (beg+end)/2;
    return get_sum_util(st, beg, mid, l, r, 2*index+1) +
            get_sum_util(st, mid+1, end, l, r, 2*index+2);
}
int get_sum(int *st, int n, int l, int r){
    if(l<0 || r>n-1 || l>r)
        return INT_MIN;
    return get_sum_util(st, 0, n-1, l, r, 0);
}
int construct_st_util(int arr[], int beg, int end, int *st, int index){
    if(beg==end){
        st[index] = arr[beg];
        return st[index];
    }
    int mid = (beg+end)/2;
    st[index] = construct_st_util(arr, beg, mid, st, 2*index+1) +
                construct_st_util(arr, mid+1, end, st, 2*index+2);
    return st[index];
}
int *construct_st(int arr[], int n){
    int h = ceil(log2((double)n));
    int size = 2*pow(2,h)-1;
    int *st = new int[size];
    st[0] = construct_st_util(arr, 0, n-1, st, 0);
    return st;
}
int main(){
    int n=6;
    int arr[n] = {1, 3, 5, 7, 9, 11};
    int *st = construct_st(arr, n);
    cout<<get_sum(st, n, 0, 2)<<endl;
    cout<<get_sum(st, n, 3, 5)<<endl;
    update(arr, n, st, 6, 2);
    cout<<get_sum(st, n, 0, 2)<<endl;
    cout<<get_sum(st, n, 3, 5)<<endl;
    return 0;
}
