#include<bits/stdc++.h>
using namespace std;
int find(int parent[], int x){
    if(parent[x]==-1)
        return x;
    return find(parent, parent[x]);
}
void union_(int parent[], int x, int y){
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}
bool is_cyclic(list<int> adj[], int v){
    int parent[v+1];
    for(int i=1;i<=v;i++)
        parent[i]=-1;
    list<int>:: iterator it;
    for(int i=1;i<=v;i++){
        for(it=adj[i].begin();it!=adj[i].end();it++){
            if(find(parent, i) == find(parent, *it))
                return true;
            else
                union_(parent, i, *it);
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
