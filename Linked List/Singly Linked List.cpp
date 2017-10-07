#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create(void);
void display(void);
void insert_at_beg(void);
void insert_at_end(void);
void insert_at(void);
void delete_beg(void);
void delete_end(void);
void delete_val(void);
void delete_all(void);
void sort_list(void);
void reverse_list(void);
void reverse_list(node *);
void print(node *);
void reverse_print(node *);
void find_middle(void);
int main()
{
    int option;
    do{
        cout<<"SINGLY LINKED LIST\n";
        cout<<"-------------------------------\n";
        cout<<"0: Create list\n";
        cout<<"1: Display\n";
        cout<<"2: Insert at beginning\n";
        cout<<"3: Insert at end\n";
        cout<<"4: Insert at given position\n";
        cout<<"5: Delete from beginning\n";
        cout<<"6: Delete from end\n";
        cout<<"7: Delete a given node\n";
        cout<<"8: Delete list\n";
        cout<<"9: Sort\n";
        cout<<"10: Reverse list\n";
        cout<<"11: Find middle element\n";
        cout<<"12: Exit\n";
        cout<<"Enter your option:";
        cin>>option;
        cout<<"-------------------------------\n";
        switch(option)
        {
        case 0:
            create();
            break;
        case 1:
            display();
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at();
            break;
        case 5:
            delete_beg();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_val();
            break;
        case 8:
            delete_all();
            break;
        case 9:
            sort_list();
            break;
        case 10:
            reverse_list(start);
            break;
        case 11:
            find_middle();
            break;
        case 12:

            break;
        default:
            cout<<"\aInvalid option!\n";
        }
    }while(option!=12);
    return 0;
}
void create()
{
    cout<<"Enter -1 to exit data entry\n";
    int data;
    cin>>data;
    while(data!=-1){
        node* new_node = new node();
        new_node->data = data;
        new_node->next=start;
        start = new_node;
        cin>>data;
    }
}
void display()
{
    if(start==NULL){
        cout<<"List is empty\a\n";
        return;
    }
    else{
        node *ptr=start;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
void insert_at_beg()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    node *new_node = new node();
    new_node->data=data;
    if(start==NULL){
        new_node->next=NULL;
        start=new_node;
    }
    else{
        new_node->next=start;
        start=new_node;
    }
}
void insert_at_end()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    node *new_node = new node();
    new_node->data=data;
    new_node->next=NULL;
    if(start==NULL){
        start=new_node;
    }
    else{
        node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
}
void insert_at()
{
    int data,pos;
    cout<<"Enter the data:";
    cin>>data;
    cout<<"Enter the position:";
    cin>>pos;
    int i=1,flag=0;
    node *ptr,*preptr;
    ptr=preptr=start;
    node *new_node = new node();
    new_node->data=data;
    while(ptr->next!=NULL){
        if(i==pos){
            flag=1;
            break;
        }
        preptr=ptr;
        ptr=ptr->next;
        i++;
    }
    if(flag==1){
        preptr->next=new_node;
        new_node->next=ptr;
        cout<<"Data inserted successfully\n";
    }
    else{
        cout<<"Error in insertion\n";
    }
}
void delete_beg()
{
    if(start==NULL){
        cout<<"List is empty\n";
    }
    else{
        node *ptr;
        ptr=start;
        start=start->next;
        delete ptr;
        cout<<"data deleted successfully\n";
    }
}
void delete_end()
{
    if(start==NULL){
        cout<<"List is empty\n";
    }
    else{
        node *ptr,*preptr;
        ptr=start;
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        delete ptr;
        cout<<"Data deleted successfully.\n";
    }
}
void delete_val()
{
    if(start==NULL){
        cout<<"List is empty\n";
    }
    else{
        int val;
        int flag=0;
        cout<<"Enter the value to delete:";
        cin>>val;
        node *ptr,*preptr;
        ptr=preptr=start;
        while(ptr->next!=NULL){
            if(ptr->data==val){
                flag=1;
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
        if(flag==1){
            if(ptr==start){
                start=ptr->next;
                delete ptr;
            }
            else{
                preptr->next=ptr->next;
                delete ptr;
            }
            cout<<"Data deleted successfully\n";
        }
        else{
            cout<<"Error in deletion\n";
        }
    }
}
void delete_all()
{
    if(start==NULL){
        cout<<"List is already empty\n";
    }
    else{
        node *ptr=start;
        while(ptr->next!=NULL){
            start=start->next;
            delete ptr;
            ptr=start;
        }
        start=NULL;
        delete ptr;
        cout<<"All data deleted\n";
    }
}
void sort_list()
{
    node *ptr1,*ptr2;
    ptr1=start;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr2->data<ptr1->data){
                int temp;
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    cout<<"List sorted successfully\n";
}
void reverse_list()
{
    node *pptr,*cptr,*nptr;
    pptr=NULL;
    cptr=start;
    while(cptr!=NULL){
        nptr=cptr->next;
        cptr->next=pptr;
        pptr=cptr;
        cptr=nptr;
    }
    start=pptr;
}
void reverse_list(node *ptr) //using recursion
{
    if(ptr->next==NULL){
        start=ptr;
        return;
    }
    reverse_list(ptr->next);
    node *q=ptr->next;
    q->next=ptr;
    ptr->next=NULL;
}
void print(node *ptr)
{
    if(ptr==NULL)
        return;
    cout<<ptr->data<<"  ";
    print(ptr->next);
}
void reverse_print(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    reverse_print(ptr->next);
    cout<<ptr->data<<"  ";
}
void find_middle()
{
    if(start==NULL){
        cout<<"List is empty\n";
        return;
    }
    node *slowptr,*fastptr;
    slowptr=start;
    fastptr=start;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    cout<<"Middle element is: "<<slowptr->data<<endl;
}
