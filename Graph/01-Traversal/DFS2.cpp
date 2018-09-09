#include<bits/stdc++.h>
using namespace std;
int _time;
struct Vertex{
    int parent;
    int color;
    int d;//discovery time
    int f;//finish time
};
void DFS_visit(list<int> adj[], Vertex ver[], int n, int s){
    stack<int> stk;
    stk.push(s);
    _time=1;
    ver[s].color=1;
    ver[s].d=_time;
    cout<<s<<" ";
    while(!stk.empty()){
        int top = stk.top();
        //cout<<top<<" ";
        bool flag=false;
        list<int>:: iterator it;
        for(it=adj[top].begin(); it!=adj[top].end();it++){
            if(ver[*it].color==0){
                flag=true;
                stk.push(*it);
                cout<<*it<<" ";
                ver[*it].d = ++_time;
                ver[*it].color = 1;
                ver[*it].parent = top;
            }
        }
        if(!flag){
            ver[stk.top()].f=++_time;
            ver[stk.top()].color = 2;
            stk.pop();
        }
    }
}
void DFS(list<int> adj[], int n, int s){
    Vertex ver[n+1];
    for(int i=1;i<=n;i++){
        ver[i].color=0;
        ver[i].parent = -1;
        ver[i].d = 0;
        ver[i].f = 0;
    }
    DFS_visit(adj, ver, n, s);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"  "<<ver[i].d<<" "<<ver[i].f<<"  "<<ver[i].parent<<"  "<<ver[i].color<<endl;
    }
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
