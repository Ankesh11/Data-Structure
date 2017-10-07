#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};
node *start=NULL;
void insertatbeg()
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    node *newnode = new node();
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
        return;
    }
    newnode->next=start;
    start->prev=newnode;
    start=newnode;
}
void insertatend()
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    node* newnode= new node();
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
        return;
    }
    node* ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    newnode->prev=ptr;
    ptr->next=newnode;
}
void insertat()
{
    int data,n;
    cout<<"Enter the position: ";
    cin>>n;
    cout<<"Enter the data: ";
    cin>>data;
    node *newnode= new node();
    newnode->data=data;
    if(n==1){
        newnode->prev=NULL;
        newnode->next=start;
        if(start!=NULL)
        start->prev=newnode;
        start=newnode;
        return;
    }
    node *ptr;
    ptr=start;
    for(int i=1;i<n-1;i++)
        ptr=ptr->next;
    newnode->next=ptr->next;
    if(ptr->next!=NULL)
    (ptr->next)->prev=newnode;
    ptr->next=newnode;
    newnode->prev=ptr;
}
void searchdata()
{
    int data,n=0,flag=0;
    cout<<"Enter the data to search: ";
    cin>>data;
    node *ptr=start;
    while(ptr!=NULL){
        n++;
        if(ptr->data==data){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1)
    cout<<data<<" found at position "<<n<<endl;
    else
        cout<<data<<" not found!\n";
}
void deleteat()
{
    int n;
    cout<<"Enter the position to delete: ";
    cin>>n;
    node *ptr1,*ptr2;
    ptr1=start;
    if(n==1){
        start=ptr1->next;
        if(ptr1->next!=NULL)
        (ptr1->next)->prev=NULL;
        delete ptr1;
        return;
    }
    for(int i=1;i<n-1;i++)
        ptr1=ptr1->next;
    ptr2=ptr1->next;
    ptr1->next=ptr2->next;
    if(ptr2->next!=NULL)
    (ptr2->next)->prev=ptr1;
    delete ptr2;
}
void deleteall()
{
    node *ptr1,*ptr2;
    ptr1=start;
    while(ptr1!=NULL){
        ptr2=ptr1->next;
        delete ptr1;
        ptr1=ptr2;
    }
    start=NULL;
}
void reverselist()
{
    node *temp,*p;
    p=start;
    while(p!=NULL){
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        start=p;
        p=p->prev;
    }
}
void display()
{
    node *p=start;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
}
void displayreverse()
{
    node* p=start;
    while(p->next!=NULL)
        p=p->next;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->prev;
    }
}
void menu()
{
    cout<<"\n\n..DOUBLY LINKED LIST.."<<endl;
    cout<<"-----------------------\n";
    cout<<"1: Insert at beginning\n";
    cout<<"2: Insert at end\n";
    cout<<"3: Insert at position...\n";
    cout<<"4: Search\n";
    cout<<"5: Delete from position...\n";
    cout<<"6: Delete all\n";
    cout<<"7: Reverse\n";
    cout<<"8: Display\n";
    cout<<"9: Display Reverse\n";
    cout<<"0: Exit\n";
}
int main()
{
    int option;
    menu();
    cout<<"Enter option: ";
    cin>>option;
    cout<<endl;
    while(option!=0){
        switch(option)
        {
        case 1:
            insertatbeg();
            break;
        case 2:
            insertatend();
            break;
        case 3:
            insertat();
            break;
        case 4:
            searchdata();
            break;
        case 5:
            deleteat();
            break;
        case 6:
            deleteall();
            break;
        case 7:
            reverselist();
            break;
        case 8:
            display();
            break;
        case 9:
            displayreverse();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Invalid option!\n";
            break;
        }
        menu();
        cout<<"Enter option: ";
        cin>>option;
        cout<<endl;
    }
    return 0;
}
