#include <iostream>

using namespace std;

int main()
{
    int arr[10],n,flag;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
