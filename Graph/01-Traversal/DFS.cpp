#include<bits/stdc++.h>
using namespace std;
int _time;
struct Vertex{
    int parent;
    int color;
    int d;//discovery time
    int f;//finish time
};
void DFS_util(list<int> adj[],Vertex v[], int n, int s){
    v[s].color = 1;
    _time++;
    v[s].d = _time;
    cout<<s<<" ";
    list<int>:: iterator it;
    for(it=adj[s].begin(); it!=adj[s].end(); it++){
        if(v[*it].color==0)
            DFS_util(adj, v, n, *it);
    }
    v[s].color = 2;
    _time++;
    v[s].f = _time;
}
void DFS(list<int> adj[], int n, int s){
    Vertex v[n+1];
    for(int i=1;i<=n;i++){
        v[i].parent = -1;
        v[i].color = 0;
    }
    _time=0;
    DFS_util(adj, v, n, s);
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
    cout<<"Enter source vertex:"<<endl;
    cin>>s;
    cout<<"DFS\n";
    DFS(adj, n, s);
    return 0;
}
