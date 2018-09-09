#include<bits/stdc++.h>
using namespace std;
bool is_bipartite_util(list<int> adj[], int color[], int s){
    queue<int> que;
    que.push(s);
    color[s]=1;
    list<int>:: iterator it;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(color[u]==color[*it])
                return false;
            if(color[*it]==-1){
                que.push(*it);
                color[*it] = 1-color[u];
            }
        }
    }
    return true;
}
bool is_bipartite(list<int> adj[], int n){
    int color[n+1];
    for(int i=1;i<=n;i++)
        color[i]=-1;
    for(int i=1;i<=n;i++){
        if(color[i]==-1)
            if(!is_bipartite_util(adj, color, i))
                return false;
    }
    return true;
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
    if(is_bipartite(adj, v))
        cout<<"Bipartite";
    else
        cout<<"Not bipartite";
    return 0;
}
