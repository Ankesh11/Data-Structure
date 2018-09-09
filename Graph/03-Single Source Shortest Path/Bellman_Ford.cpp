#include<bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,w;
};
bool bellman_ford(vector<Node> edges, int e, int n, int s){
    int dist[n];
    int parent[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        parent[i]=-1;
    }
    dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    //cycle detection
    for(int i=0;i<e;i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(dist[u]!=INT_MAX && dist[u]+w < dist[v])
            return false;
    }
    cout<<"Shortest path of each vertex from "<<s<<":\n";
    cout<<"v  dist  parent"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"  "<<dist[i]<<"  "<<parent[i]<<endl;
    }
    return true;
}
int main(){
    int n,e,u,v,w,s;
    cout<<"Enter the no of vertices:\n";
    cin>>n;
    cout<<"Enter the no of edges:\n";
    cin>>e;
    vector<Node> edges;
    cout<<"Enter vetex pair and weight of each edges:\n";
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        edges.push_back(Node{u,v,w});
    }
    cout<<"Enter the source vertex:\n";
    cin>>s;
    if(!bellman_ford(edges, e, n, s))
        cout<<"Graph contains negative weight cycle.\n";
    return 0;
}
