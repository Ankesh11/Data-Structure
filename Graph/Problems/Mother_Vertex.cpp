#include<bits/stdc++.h>
using namespace std;
void dfs(list<int> adj[], bool visited[], int s){
    visited[s] = true;
    list<int> :: iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it]==false)
            dfs(adj, visited, *it);
    }
}
int find_mother_vertex(list<int> adj[], int n){
    bool visited[n+1] = {false};
    int last_finished;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            dfs(adj, visited, i);
            last_finished = i;
        }
    }
    memset(visited, n+1, false);
    dfs(adj, visited, last_finished);
    for(int i=1;i<=n;i++){
        if(visited[i]==false)
            return -1;
    }
    return last_finished;
}
int main(){
    int n,e,p,q,s;
    cout<<"Enter the no of vertices:"<<endl;
    cin>>n;
    list<int> adj[n+1];
    cout<<"Enter the no of edges:"<<endl;
    cin>>e;
    cout<<"Enter vertex pair of each edges:"<<endl;
    for(int i=0;i<e;i++){
        cin>>p>>q;
        adj[p].push_front(q);
    }
    cout<<"Mother vertex: ";
    cout<<find_mother_vertex(adj, n);
    return 0;
}
