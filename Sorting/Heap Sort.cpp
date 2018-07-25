#include<bits/stdc++.h>
using namespace std;
int size = 0;
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void max_heapify(int arr[],int i){
	int leftc = i*2+1;
	int rightc = i*2+2;
	int largest = i;
	if(leftc<size && arr[leftc]>arr[largest])
		largest = leftc;
	if(rightc<size && arr[rightc]>arr[largest])
		largest = rightc;
	if(largest!=i){
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest);
	}
}
void build_heap(int *arr){
	for(int i=(size-1)/2;i>=0;i--)
		max_heapify(arr,i);
}
void heap_sort(int arr[], int n){
	size = n;
	build_heap(arr);
	for(int i=size-1;i>=1;i--){
		swap(arr[0],arr[i]);
		size--;
		max_heapify(arr,0);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	heap_sort(arr,n);
	cout<<"Sorted array:\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
