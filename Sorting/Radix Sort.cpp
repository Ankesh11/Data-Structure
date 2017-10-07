#include <iostream>

using namespace std;
int getMax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<=n;i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
void counting_sort(int a[],int n,int d)
{
    int output[n+1];
    int c[10]={0};
    for(int i=1;i<=n;i++)
        c[(a[i]/d)%10]++;
    for(int i=1;i<10;i++)
        c[i]=c[i]+c[i-1];
    for(int i=n;i>=1;i--){
        output[c[(a[i]/d)%10]]=a[i];
        c[(a[i]/d)%10]--;
    }
    for(int i=1;i<=n;i++)
        a[i]=output[i];
}
void radixSort(int arr[],int n)
{
    int max = getMax(arr,n);
    for(int d=1;max/d>0;d*=10)
        counting_sort(arr,n,d);
}
int main()
{
    int n,arr[100];
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    radixSort(arr,n);
    cout<<"Sorted elements\n";
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
