#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//Max heap
class max_heap{
    int *heap;
    int size;
    int capacity;
public:
    max_heap(int cap){
        heap = new int[cap];
        capacity = cap;
        size=0;
    }
    max_heap(int arr[],int n){
        capacity = n;
        size = n;
        heap = arr;
        build_heap();
    }
    void build_heap(){
        for(int i=(size-1)/2;i>=0;i--)
            max_heapify(i);
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
    void max_heapify(int i){
        int l = left_child(i);
        int r = right_child(i);
        int largest = i;
        if(l<size && heap[l]>heap[largest])
            largest = l;
        if(r<size && heap[r]>heap[largest])
            largest = r;
        if(largest!=i){
            swap(heap[largest], heap[i]);
            max_heapify(largest);
        }
    }
    void insert_key(int key){
        heap[size]=INT_MIN;
        size++;
        increase_key(size-1,key);
    }
    void increase_key(int i,int new_key){
        if(heap[i]>new_key)
            return;
        heap[i]=new_key;
        while(i>0 && heap[parent(i)]<heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    int extract_max(){
        if(size==0)
            return INT_MIN;
        int max = heap[0];
        heap[0]=heap[size-1];
        size--;
        max_heapify(0);
        return max;
    }
    int get_max(){
        if(size==0)
            return INT_MIN;
        return heap[0];
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
    //Create max_heap object and use the function here
    return 0;
}
