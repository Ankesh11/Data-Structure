#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
void rotate_(int arr[],int n,int d){
    for(int i=0;i<gcd(n,d);i++){
        int j = i;
        int temp = arr[i];
        while(1){
            int k = j+d;
            if(k >= n)
                k = k-n;
            if(k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
int main()
{
    int n,d;
    cout<<"Enter the no of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the no of rotation: ";
    cin>>d;
    rotate_(arr,n,d);
    cout<<"Rotated array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

// Time Complexity: O(n)