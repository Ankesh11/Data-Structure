/* Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1].
The idea of the algorithm is:
Reverse A to get ArB. Ar is reverse of A
Reverse B to get ArBr. Br is reverse of B
Reverse all to get (ArBr) r = BA.
*/

#include <iostream>
using namespace std;
void reverse_(int arr[],int b,int e){
    int temp;
    while(b<e){
        temp = arr[b];
        arr[b] = arr[e];
        arr[e] = temp;
        b++;
        e--;
    }
}
void rotate_(int arr[],int n,int d){
    reverse_(arr,0,d-1);
    reverse_(arr,d,n-1);
    reverse_(arr,0,n-1);
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

//Time Complexity: O(n)