#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int v;
    int w;
};
struct HeapNode{
    int v;
    int dist;
};
struct Output{
    int parent;
    int dist;
};
class MinHeap{
    HeapNode *heap;
    int *pos;
    int size;
public:
    MinHeap(HeapNode *heap, int n){
        this->heap = heap;
        size = n;
        pos = new int[n];
        for(int i=0;i<n;i++)
            pos[i]=i;
        build_heap();
    }
    void build_heap(){
        for(int i=(size-1)/2;i>=0;i--)
            min_heapify(i);
    }
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    void swap(HeapNode &a, HeapNode &b){
        HeapNode temp = a;
        int t = pos[a.v];
        pos[a.v] = pos[b.v];
        pos[b.v] = t;
        a = b;
        b = temp;
    }
    void min_heapify(int i){
        int smallest = i;
        int l = left_child(i);
        int r = right_child(i);
        if(l<size && heap[l].dist<heap[smallest].dist)
            smallest = l;
        if(r<size && heap[r].dist<heap[smallest].dist)
            smallest = r;
        if(smallest!=i){
            swap(heap[smallest], heap[i]);
            min_heapify(smallest);
        }
    }
    HeapNode extract_min(){
        HeapNode temp = heap[0];
        heap[0] = heap[size-1];
        pos[heap[0].v] = 0;
        size--;
        min_heapify(0);
        return temp;
    }
    void decrease_key(int v, int key){
        int i = pos[v];
        heap[i].dist = key;
        while(i>0 && heap[i].dist < heap[parent(i)].dist){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    bool empty(){return (size==0);}
};
void dijkstras(list<ListNode> adj[], int n, int s){
    //Initialization
    Output res[n];
    for(int i=0;i<n;i++){
        res[i].parent = -1;
        res[i].dist = INT_MAX;
    }
    res[s].dist = 0;
    bool visited[n] = {false};
    //Building Heap
    HeapNode *heap = new HeapNode[n];
    for(int i=0;i<n;i++){
        heap[i].v=i;
        heap[i].dist=INT_MAX;
    }
    heap[s].dist=0;
    MinHeap mh(heap, n);
    //Relaxing
    list<ListNode>:: iterator it;
    while(!mh.empty()){
        HeapNode temp = mh.extract_min();
        int u = temp.v;
        int udist = temp.dist;
        visited[u]=true;
        for(it = adj[u].begin();it!=adj[u].end();it++){
            if(!visited[it->v] && udist+it->w < res[it->v].dist){
                res[it->v].dist = udist+it->w;
                res[it->v].parent = u;
                mh.decrease_key(it->v, udist+it->w);
            }
        }
    }
    cout<<"Shortest path from "<<s<<":\n";
    cout<<"Vertex  Distance  Parent"<<endl;
    for(int i=0;i<n;i++)
        cout<<i<<"     "<<res[i].dist<<"     "<<res[i].parent<<endl;
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
    dijkstras(adj, n, s);
}
//Time Complexity: O(VlgV + ElgV)
