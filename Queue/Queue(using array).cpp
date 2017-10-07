#include<iostream>
#define SIZE 10
using namespace std;
int que[SIZE];
int f=-1,r=-1;
void insert_data(int);
void display(void);
void delete_data(void);
void reverse_que(void);
int main()
{
    int option,val;
    do{
        cout<<"\n---QUEUE---\n";
        cout<<"1: Insert\n";
        cout<<"2: Delete\n";
        cout<<"3: Reverse\n";
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
            reverse_que();
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
    if(r==SIZE-1){
        cout<<"Overflow\n";
        return;
    }
    else if(f==-1 && r==-1){
        f=r=0;
        que[r]=data;
    }
    else{
        r++;
        que[r]=data;
    }
    cout<<"Data inserted successfully\n";
}
void display()
{
    if(f==-1 && r==-1){
        cout<<"Underflow\n";
    }
    else{
        for(int i=f;i<=r;i++){
            cout<<que[i]<<"  ";
        }
    }
}
void delete_data()
{
    if(f==-1 || f>r){
        cout<<"Underflow\n";
        return;
    }
    else if(f==r){
        f=r=-1;
        return;
    }
    else{
        f++;
    }
}
void reverse_que()
{
    int i=f;
    int j=r;
    while(i<j){
        que[i]=que[i]^que[j];
        que[j]=que[i]^que[j];
        que[i]=que[i]^que[j];
        i++;
        j--;
    }
}
