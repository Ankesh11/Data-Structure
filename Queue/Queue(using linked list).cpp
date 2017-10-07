#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *f=NULL;
node *r=NULL;
void insert_data(int);
void display(void);
void delete_data(void);
int main()
{
    int option,val;
    do{
        cout<<"\n---QUEUE---\n";
        cout<<"1: Insert\n";
        cout<<"2: Delete\n";
        cout<<"3: Peek\n";
        cout<<"4: Display\n";
        cout<<"5: Exit\n";
        cout<<"Enter option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter data to insert: ";
            cin>>val;
            insert_data(val);
            break;
        case 2:
            delete_data();
            break;
        case 3:

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
void insert_data(int data)
{
    node *new_node = new node();
    new_node->data=data;
    new_node->next=NULL;
    if(f==NULL && r==NULL){
        f=r=new_node;
    }
    else{
        r->next=new_node;
        r=new_node;
    }
    cout<<"Data inserted successfully\n";
}
void display()
{
    if(f==NULL && r==NULL){
        cout<<"Underflow\n";
    }
    else{
        node *ptr=f;
        while(ptr!=r){
            cout<<ptr->data<<"  ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
}
void delete_data()
{
    if(f==NULL && r==NULL){
        cout<<"Underflow\n";
    }
    else if(f==r){
        node *ptr=f;
        f=r=NULL;
        delete ptr;
    }
    else{
        node *ptr=f;
        f=f->next;
        delete ptr;
        cout<<"Data deleted successfully\n";
    }
}
