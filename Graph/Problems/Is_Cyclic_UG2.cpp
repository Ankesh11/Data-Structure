#include<bits/stdc++.h>
using namespace std;
bool is_cyclic_util(list<int> adj[], int visited[], int s, int p){
    visited[s]=1;
    list<int>:: iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it]==1 && *it!=p)
            return true;
        if(visited[*it]==0){
            if(is_cyclic_util(adj, visited, *it, s))
                return true;
        }
    }
    return false;
}
bool is_cyclic(list<int> adj[], int v){
    int visited[v+1]={0};
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
            if(is_cyclic_util(adj, visited, i, -1))
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
        adj[q].push_front(p);
    }
    if(is_cyclic(adj, v))
        cout<<"Cyclic\n";
    else
        cout<<"Acyclic\n";
    return 0;
}
