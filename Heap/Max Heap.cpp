#include<iostream>
#include<string.h>
#include<cstring>
#define MAX 20
using namespace std;
int N=-1;
void percolate_up(int heap[],int val)
{
    N++;
    heap[N]=val;
    int c=N;
    int p=(N-1)/2;
    while(heap[p]<heap[c] && c>0){
        int temp=heap[p];
        heap[p]=heap[c];
        heap[c]=temp;
        c=p;
        p=(p-1)/2;
    }
}
int percolate_down(int heap[])
{
    int temp=heap[0];
    heap[0]=heap[N];
    N--;
    int p=0,c1=(2*p)+1,c2=(2*p)+2;
    if(heap[p]>=heap[c1] && heap[p]>=heap[c2])
        return temp;
    else{
        while((heap[p]<heap[c1] || heap[p]<heap[c2]) && c1<=N){
            if(heap[c1]>heap[c2]){
                int temp=heap[c1];
                heap[c1]=heap[p];
                heap[p]=temp;
                p=c1;
                c1=(2*p)+1;
                c2=(2*p)+2;
            }
            else{
                int temp=heap[c2];
                heap[c2]=heap[p];
                heap[p]=temp;
                p=c2;
                c1=(2*p)+1;
                c2=(2*p)+2;
            }
        }
    }
    return temp;
}
void display(int heap[])
{
    for(int i=0;i<=N;i++)
        cout<<heap[i]<<"  ";
}
int main()
{
    int heap[20],val,opt;
    do{
        cout<<"\n---MAX HEAP---\n";
        cout<<"1: Insert\n";
        cout<<"2: Delete\n";
        cout<<"3: Display\n";
        cout<<"4: Exit\n";
        cout<<"Enter your option: ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            cout<<"Enter data to insert: ";
            cin>>val;
            percolate_up(heap,val);
            break;
        case 2:
            val=percolate_down(heap);
            cout<<"Deleted value: "<<val<<endl;
            break;
        case 3:
            display(heap);
            break;
        case 4:
            break;
        }
    }while(opt!=4);
    return 0;
}
