#include <iostream>
using namespace std;
void quick_sort(int *,int,int);
int partition_index(int *,int,int);
int main()
{
    int arr[10],n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
void quick_sort(int arr[],int b,int e)
{
    int pi;
    if(b<e){
        pi=partition_index(arr,b,e);
        quick_sort(arr,b,pi-1);
        quick_sort(arr,pi+1,e);
    }
}
int partition_index(int arr[],int b,int e)
{
    int pivot=arr[e];
    int pi=b,temp;
    for(int i=b;i<e;i++){
        if(arr[i]<=pivot){
            temp=arr[i];
            arr[i]=arr[pi];
            arr[pi]=temp;
            pi++;
        }
    }
    temp=arr[pi];
    arr[pi]=arr[e];
    arr[e]=temp;
    return pi;
}
