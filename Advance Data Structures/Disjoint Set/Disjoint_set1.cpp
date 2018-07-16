#include<bits/stdc++.h>
using namespace std;
bool find(int parent[], int a, int b){
    if(parent[a] == parent[b])
        return true;
    return false;
}
void union(int parent[],int a,int b,int n){
    if(!find(parent, a, b)){
        int temp = parent[a];
        for(int i=0;i<n;i++){
            if(parent[i]==temp)
                parent[i]=parent[b];
        }
    }
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

//Time Complexity: Find- O(1), Union- O(n)
