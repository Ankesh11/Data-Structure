#include<bits/stdc++.h>
using namespace std;
struct MSTNode{
    int parent;
    int key;
};
struct Node{
    int v;
    int w;
};
struct MinHeapNode{
    int v;
    int key;
};
class min_heap{
    MinHeapNode *heap;
    int size;
    int capacity;
public:
    min_heap(int n){
        size=n;
        capacity=n;
        heap = new MinHeapNode[n];
        for(int i=0;i<n;i++){
            heap[i] = MinHeapNode{i+1, INT_MAX};
        }
        heap[0]->key = 0;
    }
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    void build_heap(){
        for(int i=(size-1)/2;i>=0;i--)
            min_heapify(i);
    }
    void min_heapify(int i){
        int smallest = i;
        int l = left_child(i);
        int r = right_child(i);
        if(l<size && heap[l]->key<heap[smallest]->key)
            smallest = l;
        if(r<size && heap[r]->key<heap[smallest]->key)
            smallest = r;
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            min_heapify(smallest);
        }
    }
    MinHeapNode extract_min(){
        MinHeapNode temp = heap[0];
        heap[0] = heap[size-1];
        size--;
        min_heapify(0);
        return temp;
    }
    bool empty(){return (size==0);}
}
void prims_mst(list<Node> adj[], int n){
    min_heap mh(n);

    MSTNode res[n+1];
    bool incl_in_mst[n+1] = {false};
    list<Node>::iterator it;
    while(!mh.empty()){
        MinHeapNode node = mh.extract_min();
        for(it=adj[node.v].begin();it!=adj[node.v].end();it++){
            if(incl_in_mst[it->v]==false && it->w<node)
        }
    }
}
int main(){
    int n,e,u,v,w;
    cout<<"Enter the no of vertices:"<<endl;
    cin>>n;
    list<Node> adj[n+1];
    cout<<"Enter the no of edges:"<<endl;
    cin>>e;
    cout<<"Enter vertex pair and weight of each edges"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_front(Node{v,w});
        adj[v].push_front(Node{u,w});
    }
    prims_mst(adj, n);
    return 0;
}
