#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26
struct TrieNode{
    TrieNode *child[ALPHABET_SIZE];
    int prefix_count;
    bool eow;
};
TrieNode *get_node(){
    TrieNode *node = new TrieNode;
    node->prefix_count = 0;
    node->eow = false;
    for(int i=0;i<ALPHABET_SIZE;i++)
        node->child[i] = NULL;
    return node;
}
void insert(TrieNode *root, string key){
    TrieNode *ptr = root;
    ptr->prefix_count++;
    int len = key.length();
    for(int i=0;i<len;i++){
        int index = key[i]-'a';
        if(ptr->child[index]==NULL)
            ptr->child[index] = get_node();
        ptr = ptr->child[index];
        ptr->prefix_count++;
    }
    ptr->eow = true;
}
bool search(TrieNode *root, string key){
    TrieNode *ptr = root;
    int len = key.length();
    for(int i=0;i<len;i++){
        int index = key[i]-'a';
        if(ptr->child[index]==NULL)
            return false;
        ptr = ptr->child[index];
    }
    return (ptr!=NULL && ptr->eow==true);
}
bool is_mapped(TrieNode *ptr){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(ptr->child[i]!=NULL)
            return true;
    }
    return false;
}
bool delete_word(TrieNode *ptr, string key, int index){
    if(ptr==NULL)
        return false;
    if(index == key.length()){
        if(ptr->eow==false)
            return false;
        ptr->eow = false;
        if(!is_mapped(ptr)){
            ptr->prefix_count--;
            return true;
        }
        return false;
    }
    int i = key[index]-'a';
    bool flag = delete_word(ptr->child[key[index]-'a'], key, index+1);
    ptr->prefix_count--;
    if(flag){
        TrieNode *temp = ptr->child[i];
        ptr->child[i] = NULL;
        delete temp;
        if(!is_mapped(ptr) && ptr->eow==false)
            return true;
    }
    return false;
}
int prefix_word_count(TrieNode *ptr, string prefix){
    int len = prefix.length();
    for(int i=0;i<len;i++){
        int index = prefix[i]-'a';
        if(ptr->child[index]==NULL || ptr==NULL)
            return 0;
        ptr = ptr->child[index];
    }
    return ptr->prefix_count;
}
void prefix_search_display(TrieNode *ptr, string prefix){
    if(ptr->eow==true){
        cout<<prefix<<endl;
    }
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(ptr->child[i]!=NULL)
            prefix_search_display(ptr->child[i], prefix + char('a'+i));
    }
}
void prefix_search(TrieNode *ptr, string str){
    string prefix = "";
    TrieNode *prev = ptr;
    int len = str.length();
    for(int i=0;i<len;i++){
        prefix += str[i];
        TrieNode *curr = prev->child[prefix[i]-'a'];
        if(curr==NULL)
            break;
        prefix_search_display(curr, prefix);
        prev = curr;
    }
}
int main(){
    TrieNode *root = get_node();
    insert(root, "gary");
    insert(root, "gayle");
    insert(root, "andy");
    insert(root, "alex");
    insert(root, "amazon");
    insert(root, "alexa");
    cout<<search(root, "and")<<endl;
    cout<<search(root, "amazon")<<endl;
    cout<<search(root, "alexa")<<endl;

    delete_word(root, "amazon", 0);
    cout<<search(root, "amazon")<<endl;

    cout<<prefix_word_count(root, "a")<<endl;

    prefix_search(root, "al");
    return 0;
}
