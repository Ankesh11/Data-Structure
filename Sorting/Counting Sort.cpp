#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of elements:\n";
    cin>>n;
    int a[n+1],b[n+1];
    cout<<"Enter the elements[0,100):\n";
    int c[100]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<100;i++)
        c[i]=c[i]+c[i-1];
    for(int i=n;i>=1;i--){
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    cout<<"Sorted array:\n";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}
