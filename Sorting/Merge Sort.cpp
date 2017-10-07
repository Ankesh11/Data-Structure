#include <iostream>
#include <limits.h>
using namespace std;
void merge_array(int arr[],int b,int m,int e)
{
    int n1 = m-b+1;
    int n2 = e-m;
    int l1[n1+1];
    int l2[n2+1];
    for(int i=0;i<n1;i++)
        l1[i]=arr[b+i];
    for(int i=0;i<n2;i++)
        l2[i]=arr[m+i+1];
    l1[n1]=INT_MAX;
    l2[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=b;k<=e;k++){
        if(l1[i]<=l2[j]){
            arr[k]=l1[i];
            i++;
        }
        else{
            arr[k]=l2[j];
            j++;
        }
    }
}
void merge_sort(int arr[],int b,int e)
{
    if(b<e){
        int mid = (b+e)/2;
        merge_sort(arr,b,mid);
        merge_sort(arr,mid+1,e);
        merge_array(arr,b,mid,e);
    }
}
int main()
{
    int arr[10],n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
/*void merge_array(int arr[],int b,int mid,int e)
{
    int i=b,j=mid+1,temp[10],k=b;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int i=0;i<k;i++)
        arr[i]=temp[i];
}*/
