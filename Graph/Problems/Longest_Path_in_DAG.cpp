#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v;
    int w;
};
void topological_sort(list<Node> adj[], int visited[], stack<int> &tsort, int s){
    visited[s]=1;
    list<Node>:: iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(visited[it->v]==0)
            topological_sort(adj, visited, tsort, it->v);
    }
    tsort.push(s);
}
void longest_path(list<Node> adj[], int n, int s){
    stack<int> tsort;
    int visited[n+1] = {0};
    for(int i=1;i<=n;i++){
        if(visited[i]==0)
            topological_sort(adj, visited, tsort, i);
    }
    int dist[n+1];
    for(int i=1;i<=n;i++)
        dist[i] = INT_MIN;
    dist[s] = 0;
    list<Node> :: iterator it;
    while(!tsort.empty()){
        int u = tsort.top();
        tsort.pop();
        for(it=adj[u].begin();it!=adj[u].end();it++){
            int v = it->v;
            int w = it->w;
            if(dist[u]!=INT_MIN){
                if(dist[u]+w > dist[v])
                    dist[v] = dist[u]+w;
            }
        }
    }
    cout<<"Longest distance of each vertex from "<<s<<" are:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}
int main(){
    int v,e,p,q,w,s;
    cout<<"Enter the no of vertex:\n";
    cin>>v;
    list<Node> adj[v+1];
    cout<<"Enter the no of egdes:\n";
    cin>>e;
    cout<<"Enter vertex pair and weight of each edges:\n";
    for(int i=0;i<e;i++){
        cin>>p>>q>>w;
        Node temp = {q,w};
        adj[p].push_front(temp);
    }
    cout<<"Enter the source vertex:\n";
    cin>>s;
    longest_path(adj, v, s);
    return 0;
}
