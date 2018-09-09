#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int v;
    int w;
};
void topological_sort_util(list<ListNode> adj[], bool visited[], int i, stack<int> &stk){
    visited[i]=true;
    list<ListNode>:: iterator it;
    for(it= adj[i].begin();it!=adj[i].end();it++){
        if(visited[it->v]==false)
            topological_sort_util(adj, visited, it->v, stk);
    }
    stk.push(i);
}
stack<int> topological_sort(list<ListNode> adj[], int n){
    bool visited[n] = {false};
    stack<int> stk;
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            topological_sort_util(adj, visited, i, stk);
    }
    return stk;
}
void shortest_path(list<ListNode> adj[], int n, int s){
    stack<int> stk = topological_sort(adj, n);
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i] = INT_MAX;
    dist[s] = 0;
    list<ListNode>:: iterator it;
    while(!stk.empty()){
        int u = stk.top();
        if(dist[u]!=INT_MAX){
            for(it = adj[u].begin();it!=adj[u].end();it++){
                if(dist[u]+it->w < dist[it->v])
                    dist[it->v] = dist[u] + it->w;
            }
        }
        stk.pop();
    }
    cout<<"Distance of each vertex from "<<s<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]!=INT_MAX)
            cout<<dist[i]<<" ";
        else
            cout<<"INF ";
    }
}
int main(){
    int n, e, u, v, w, s;
    cout<<"Enter the no of vertices:\n";
    cin>>n;
    list<ListNode> adj[n];
    cout<<"Enter the no of edges:\n";
    cin>>e;
    cout<<"Enter vertex pair and weight of each edges:\n";
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_front(ListNode{v, w});
    }
    cout<<"Enter the source vertex:\n";
    cin>>s;
    shortest_path(adj, n, s);
    return 0;
}
