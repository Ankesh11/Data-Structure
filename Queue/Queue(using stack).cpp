#include <iostream>
#define MAX 10
using namespace std;
int stk1[MAX];
int stk2[MAX];
int top1=-1,top2=-1;
void enque(int);
void deq(void);
void display(void);
void push1(int);
int pop1(void);
void push2(int);
int pop2(void);
int main()
{
    int option,val;
    do{
        cout<<"\nQUEUE USING STACK\n";
        cout<<"1: Enque\n";
        cout<<"2: Deque\n";
        cout<<"3: Display\n";
        cout<<"4: Exit\n";
        cout<<"Enter your option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter the data: ";
            cin>>val;
            enque(val);
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:

            break;
        }
    }while(option!=4);
    return 0;
}
void push1(int val)
{
    if(top1==MAX-1){
        cout<<"Overflow\n";
        return;
    }
    else{
        stk1[++top1]=val;
    }
}
void push2(int val)
{
    if(top2==MAX-1){
        cout<<"Overflow\n";
        return;
    }
    else{
        stk2[++top2]=val;
    }
}
int pop1()
{
    if(top1==-1){
        cout<<"Underflow\n";
        return -1;
    }
    else{
        return stk1[top1--];
    }
}
int pop2()
{
    if(top2==-1){
        cout<<"Underflow\n";
        return -1;
    }
    else{
        return stk2[top2--];
    }
}
void display()
{
    if(top1==-1){
        cout<<"Queue is empty\n";
        return;
    }
    else{
        for(int i=0;i<=top1;i++)
            cout<<stk1[i]<<"  ";
    }
}
void enque(int val)
{
    if(top1==MAX-1){
        cout<<"Overflow\n";
        return;
    }
    stk1[++top1]=val;
}
void deq()
{
    if(top1==-1){
        cout<<"Underflow\n";
        return;
    }
    while(top1!=-1){
        push2(pop1());
    }
    pop2();
    while(top2!=-1){
        push1(pop2());
    }
}
