#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u;
    int v;
    int w;
};
struct Subset{
    int parent;
    int rank;
};
int find(Subset subsets[], int x){
    if(subsets[x].parent==-1)
        return x;
    subsets[x].parent = find(subsets, subsets[x].parent);
    return subsets[x].parent;
}
void union_(Subset subsets[], int x, int y){
    int xp = find(subsets, x);
    int yp = find(subsets, y);
    if(subsets[xp].rank > subsets[yp].rank)
        subsets[yp].parent = xp;
    else if(subsets[xp].rank < subsets[yp].rank)
        subsets[xp].parent = yp;
    else{
        subsets[yp].parent = xp;
        subsets[xp].rank++;
    }
}
void make_set(Subset subsets[], int n){
    for(int i=0;i<=n;i++){
        subsets[i].parent = -1;
        subsets[i].rank = 0;
    }
}
bool comp(Edge e1, Edge e2){
    return (e1.w<=e2.w);
}
void kruskal(Edge edges[], int e, int n){
    sort(edges, edges+e, comp);
    Subset subsets[n+1];
    make_set(subsets, n);
    vector<Edge> output;
    for(int i=0;i<e;i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(find(subsets, u) != find(subsets, v)){
            output.push_back(Edge{u,v,w});
            union_(subsets, u, v);
        }
    }
    cout<<"Edges of MST are:\n";
    for(int i=0;i<output.size();i++)
        cout<<output[i].u<<"----"<<output[i].v<<"   "<<output[i].w<<endl;
}
int main(){
    int n,e,u,v,w;
    cout<<"Enter the no of Vertices:\n";
    cin>>n;
    cout<<"Enter the no of edges:\n";
    cin>>e;
    Edge edges[e];
    cout<<"Enter src, dest and weight of each edges:\n";
    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    kruskal(edges, e, n);
    return 0;
}
//Time Complexity: O(ElgV + ElgE)
