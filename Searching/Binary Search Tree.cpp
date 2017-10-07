#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    int beg_p,end_p,mid_p,n,num,flag=0;
    cout<<"Enter the no of elements: ";
    cin>>n;
    cout<<"Enter the elements in ascending order\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the no to search :";
    cin>>num;
    beg_p=0;
    end_p=n-1;
    while(beg_p<=end_p){
        mid_p=(beg_p+end_p)/2;
        if(arr[mid_p]==num){
            flag=1;
            cout<<num<<" is found at position "<<mid_p<<endl;
            break;
        }
        else{
            if(num<arr[mid_p])
                end_p=mid_p-1;
            else
                beg_p=mid_p+1;
        }
    }
    if(flag==0)
        cout<<num<<" is not found!";
    return 0;
}
