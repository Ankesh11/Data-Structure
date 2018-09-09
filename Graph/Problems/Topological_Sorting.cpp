#include<bits/stdc++.h>
using namespace std;
void topological_sort_util(list<int> adj[], list<int> &tsort, bool visited[], int s){
    stack<int> stk;
    stk.push(s);
    visited[s]=true;
    list<int> ::iterator it;
    while(!stk.empty()){
        int top = stk.top();
        bool flag = false;
        for(it=adj[top].begin();it!=adj[top].end();it++){
            if(visited[*it]==false){
                stk.push(*it);
                visited[*it]=true;
                flag = true;
            }
        }
        if(!flag){
            tsort.push_front(top);
            stk.pop();
        }
    }

}
void topological_sort(list<int> adj[], int n){
    bool visited[n+1] = {false};
    list<int> tsort;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            topological_sort_util(adj, tsort, visited, i);
        }
    }
    list<int> :: iterator it;
    cout<<"Topologically Sorted:\n";
    for(it=tsort.begin();it!=tsort.end();it++)
        cout<<*it<<" ";
}
int main(){
    int n,e,p,q;
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
    topological_sort(adj, n);
}
