#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top=NULL;
void push(int);
int pop(void);
int peek(void);
void display(void);
int main()
{
    int option,data,val;
    do{
        cout<<"\n----STACK----\n";
        cout<<"1: Push\n";
        cout<<"2: Pop\n";
        cout<<"3: Peek\n";
        cout<<"4: Display\n";
        cout<<"5: Exit\n";
        cout<<"Enter your option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter data to pop: ";
            cin>>data;
            push(data);
            break;
        case 2:
            val=pop();
            if(val==-1){
                cout<<"Stack is empty\n";
            }
            else{
                cout<<"Popped element: "<<val<<endl;
            }
            break;
        case 3:
            val=peek();
            if(val==-1){
                cout<<"Stack is empty\n";
            }
            else{
                cout<<"Top element: "<<val<<endl;
            }
            break;
        case 4:
            display();
            break;
        case 5:

            break;
        default:
            cout<<"Invalid option\n";
            break;
        }
    }while(option!=5);
    return 0;
}
void push(int data)
{
    node *new_node = new node();
    new_node->data=data;
    if(top==NULL){
        new_node->next=NULL;
        top=new_node;
    }
    else{
        new_node->next=top;
        top=new_node;
    }
    cout<<"Data inserted successfully\n";
}
int pop()
{
    int val;
    if(top==NULL){
        return -1;
    }
    else{
        node *ptr=top;
        val=top->data;
        top=top->next;
        delete ptr;
        return val;
    }
}
int peek()
{
    if(top==NULL){
        return -1;
    }
    else{
        return top->data;
    }
}
void display()
{
    if(top==NULL){
        cout<<"Stack is empty\n";
    }
    else{
        node *ptr=top;
        while(ptr!=NULL){
            cout<<"\t"<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }
}
