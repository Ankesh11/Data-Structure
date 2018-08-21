#include<bits/stdc++.h>
using namespace std;
struct subset{
    int parent;
    int rank;
};
void init(subset s[], int n){
    for(int i=0;i<=n;i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
}
int find(subset s[], int x){
    if(s[x].parent!=x)
        s[x].parent = find(s, s[x].parent);
    return s[x].parent;
}
void union_(subset s[], int x, int y){
    int xp = find(s, x);
    int yp = find(s, y);
    if(s[xp].rank < s[yp].rank)
        s[xp].parent = yp;
    else if(s[xp].rank > s[yp].rank)
        s[yp].parent = xp;
    else{
        s[yp].parent = xp;
        s[xp].rank++;
    }
}
int main(){
    int n;
    cout<<"Enter the no of elements:\n";
    cin>>n;
    subset s[n+1];
    init(s, n);
    union_(s, 1, 2);
    union_(s, 2, 3);
    union_(s, 4, 5);
    union_(s, 6, 7);
    union_(s, 5, 6);
    union_(s, 3, 7);
    cout<<"Parent of 2 before path compression: "<<s[2].parent<<endl;
    find(s, 2);
    cout<<"Parent of 2 after path compression: "<<s[2].parent<<endl;
    return 0;
}
