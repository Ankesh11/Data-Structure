#include <iostream>
using namespace std;
int main()
{
    int arr[10],n,temp,j;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(temp<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
