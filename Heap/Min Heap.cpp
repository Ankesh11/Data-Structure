#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//Min Heap
class min_heap{
    int *heap;
    int capacity;
    int size;
public:
    min_heap(int capacity){
        this->capacity = capacity;
        size=0;
        heap = new int[capacity];
    }
    min_heap(int arr[], int n){
        size = n;
        capacity = n;
        heap = arr;
        build_heap();
    }
    void build_heap(){
        for(int i=(size-1)/2;i>=0;i--){
            min_heapify(i);
        }
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left_child(int i){
        return 2*i+1;
    }
    int right_child(int i){
        return 2*i+2;
    }
    void insert_key(int key){
        if(size==capacity){
            cout<<"Overflow!"<<endl;
            return;
        }
        size++;
        int i = size-1;
        heap[i]=key;
        while(i>0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void min_heapify(int i){
        int l = left_child(i);
        int r = right_child(i);
        int smallest = i;
        if(l<size && heap[l]<heap[i])
            smallest = l;
        if(r<size && heap[r]<heap[l])
            smallest = r;
        if(smallest != i){
            swap(heap[smallest], heap[i]);
            min_heapify(smallest);
        }
    }
    int get_min(){
        if(size==0){
            cout<<"Underflow";
            return INT_MAX;
        }
        return heap[0];
    }
    int extract_min(){
        if(size<=0)
            return INT_MAX;
        else if(size==1){
            size--;
            return heap[0];
        }
        int temp = heap[0];
        heap[0] = heap[size-1];
        size--;
        min_heapify(0);
        return temp;
    }
    void decrease_key(int i, int newkey){
        heap[i] = newkey;
        while(i!=0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void delete_key(int i){
        decrease_key(i, INT_MIN);
        extract_min();
    }
    int get_size(){
        return size;
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<heap[i]<<" ";
    }
};
int main(){
    //Create min_heap objects and use the function here
    return 0;
}
