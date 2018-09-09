#include<bits/stdc++.h>
using namespace std;
bool is_cyclic_util(list<int> adj[], int color[], int s){
    stack<int> stk;
    stk.push(s);
    color[s]=1;
    list<int>:: iterator it;
    while(!stk.empty()){
        int top = stk.top();
        int flag = false;
        for(it = adj[top].begin();it!=adj[top].end();it++){
            if(color[*it]==1)
                return true;
            else if(color[*it]==0){
                flag=true;
                color[*it] = 1;
                stk.push(*it);
            }
        }
        if(flag==false){
            color[top] = 2;
            stk.pop();
        }
    }
    return false;
}
bool is_cyclic(list<int> adj[], int v){
    int color[v+1] = {0};
    for(int i=1;i<=v;i++){
        if(color[i]==0){
            if(is_cyclic_util(adj, color, i))
                return true;
        }
    }
    return false;
}
int main(){
    int v,e,p,q;
    cout<<"Enter the no of vertex:\n";
    cin>>v;
    list<int> adj[v+1];
    cout<<"Enter the no of egdes:\n";
    cin>>e;
    cout<<"Enter vertex pair of each edges:\n";
    for(int i=0;i<e;i++){
        cin>>p>>q;
        adj[p].push_front(q);
    }
    if(is_cyclic(adj, v))
        cout<<"Cyclic\n";
    else
        cout<<"Acyclic\n";
    return 0;
}
