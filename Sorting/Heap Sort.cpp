#include<iostream>
#include<string.h>
#include<cstring>
#define MAX 20
using namespace std;
void swap_data(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void max_heapify(int arr[],int n,int p)
{
    int largest=p;
    int l = 2*p + 1;
    int r = 2*p + 2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=p){
        swap_data(arr[p],arr[largest]);
        max_heapify(arr,n,largest);
    }
}
void build_heap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--){
        max_heapify(arr,n,i);
    }
}
void heap_sort(int arr[],int n)
{
    build_heap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap_data(arr[i],arr[0]);
        max_heapify(arr,i,0);
    }
}
int main()
{
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    heap_sort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
