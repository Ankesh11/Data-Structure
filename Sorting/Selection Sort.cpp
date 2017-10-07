#include <iostream>

using namespace std;
void selection_sort(int *,int);
int smallest(int *,int,int);
int main()
{
    int arr[10],n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    selection_sort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
void selection_sort(int arr[],int n)
{
    int pos,temp;
    for(int i=0;i<n;i++){
        pos=smallest(arr,i,n);
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
}
int smallest(int arr[],int k,int n)
{
    int pos=k,small=arr[k];
    for(int i=k+1;i<n;i++){
        if(arr[i]<small){
            small=arr[i];
            pos=i;
        }
    }
    return pos;
}
