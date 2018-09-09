#include<bits/stdc++.h>
using namespace std;
struct Vertex{
    int parent;
    int dist;
    int color; //0-white   1-gray   2-black
};
void bfs_util(list<int> adj[], Vertex ver[], int s){
    queue<int> que;
    que.push(s);
    list<int>:: iterator it;
    while(!que.empty()){
        int u = que.front();
        cout<<u<<" ";
        for(it=adj[u].begin(); it!= adj[u].end(); it++){
            if(ver[*it].color==0){
                ver[*it].color=1;
                ver[*it].dist = ver[u].dist+1;
                ver[*it].parent = u;
                que.push(*it);
            }
        }
        que.pop();
        ver[u].color=2;
    }
}
void bfs(list<int> adj[], int n, Vertex v[], int s){
    for(int i=1;i<=n;i++){
        v[i].parent = -1;
        v[i].dist = INT_MAX;
        v[i].color = 0;
    }
    v[s].dist = 0;
    v[s].color = 1;
    bfs_util(adj, v, s);
}
void print_path(Vertex ver[], int s, int d){
    if(s==d){
        cout<<s<<" ";
        return;
    }
    else if(ver[d].parent==-1)
        cout<<"No path from "<<s<<" to "<<d<<"."<<endl;
    else{
        print_path(ver, s, ver[d].parent);
        cout<<d<<" ";
    }
}
int main(){
    //Considering directed graph
    int v,e,p,q,s;
    cout<<"Enter the no of vertices:"<<endl;
    cin>>v;
    list<int> adj[v+1];
    cout<<"Enter the no of edges:"<<endl;
    cin>>e;
    cout<<"Enter vertex pair of each edges"<<endl;
    for(int i=0;i<e;i++){
        cin>>p>>q;
        adj[p].push_front(q);
    }
    Vertex ver[v+1];
    cout<<"Enter the source vertex:"<<endl;
    cin>>s;
    bfs(adj, v, ver, s);
    cout<<endl;
    print_path(ver, 3, 2);
    cout<<endl;
    print_path(ver, 3, 1);
    return 0;
}
