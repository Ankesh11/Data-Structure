#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE 10
int top=-1;
int stk[SIZE];
void push()
{
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    if(top!=SIZE-1){
        top++;
        stk[top]=data;
    }
    else
        cout<<"Overflow!\a\n";
}
void pop()
{
    if(top==-1){
        cout<<"Stack is empty!\a\n";
    }
    else
    {
        int val=stk[top];
        top--;
        cout<<val<<" is popped out from the stack\n";
    }
}
void display()
{
    for(int i=top;i>=0;i--){
        cout<<"\t"<<stk[i]<<"\n";
    }
}
void menu()
{
    cout<<"...STACK ARRAY...\n";
    cout<<"-----------------\n";
    cout<<"1: Push\n";
    cout<<"2: Pop\n";
    cout<<"3: Display\n";
    cout<<"4: Exit\n";
}
int main()
{
    int option;
    menu();
    cout<<"Enter option: ";
    cin>>option;
    while(option!=4)
    {
        switch(option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
        menu();
        cout<<"Enter option: ";
        cin>>option;
    }
    return 0;
}
