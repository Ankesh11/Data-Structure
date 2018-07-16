#include<bits/stdc++.h>
using namespace std;
int root(int parent[], int i){
    while(i!=parent[i])
        i = parent[i];
    return i;
}
bool find(int parent[], int a, int b){
    if(root(parent,a) == root(parent, b))
        return true;
    return false;
}
void union(int parent[],int a,int b){
    int roota = root(parent, a);
    int rootb = root(parent, b);
    parent[roota] = rootb;
}
void initialize(int parent[],int n){
    for(int i=0;i<n;i++)
        parent[i]=i;
}
int main(){
    //n- No. of elements
    int n;
    cin>>n;
    int parent[n];
    initialize(parent, n);

    //Perform Operation...
    return 0;
}

//Time Complexity: Find- O(n), Union- O(n) in worst case, but it can perform better than previous one.
