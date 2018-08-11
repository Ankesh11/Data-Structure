#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
};

Node *new_node(int key){
    Node *temp = new Node();
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int get_height(Node *root){
    if(root==NULL)
        return 0;
    return root->height;
}

int get_balance(Node *root){
    if(root == NULL)
        return 0;
    return (get_height(root->left) - get_height(root->right));
}
Node *left_rotate(Node *x){
    Node *y = x->right;
    Node *t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(get_height(x->left), get_height(x->right))+1;
    y->height = max(get_height(y->left), get_height(y->right))+1;
    return y;
}
Node *right_rotate(Node *x){
    Node *y = x->left;
    Node *t = y->right;
    y->right = x;
    x->left = t;
    x->height = max(get_height(x->left), get_height(x->right))+1;
    y->height = max(get_height(y->left), get_height(y->right))+1;
    return y;
}
Node *insert(Node *root, int key){
    if(root == NULL)
        return new_node(key);
    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balance = get_balance(root);
    if(balance > 1 && key < root->left->key)
        return right_rotate(root);
    if(balance < -1 && key > root->right->key)
        return left_rotate(root);
    if(balance > 1 && key > root->left->key){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && key < root->right->key){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
Node *minimum(Node *root){
    while(root->left!=NULL)
        root = root->left;
    return root;
}
Node *delete_key(Node *root, int key){
    if(root==NULL)
        return NULL;
    if(key < root->key)
        root->left = delete_key(root->left, key);
    else if(key > root->key)
        root->right = delete_key(root->right, key);
    else{
        if(root->left==NULL || root->right==NULL){
            Node *temp = (root->left)?root->left:root->right;
            if(temp==NULL){
                temp = root;
                root=NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else{
            Node *temp = minimum(root->right);
            root->key = temp->key;
            root->right = delete_key(root->right, temp->key);
        }
    }
    if(root==NULL)
        return root;
    root->height = 1+ max(get_height(root->left), get_height(root->right));
    int balance = get_balance(root);
    if(balance > 1 && get_balance(root->left)>=0)
        return right_rotate(root);
    if(balance>1 && get_balance(root->left)<0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance<-1 && get_balance(root->right)<=0)
        return left_rotate(root);
    if(balance<-1 && get_balance(root->right)>0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    preorder(root); cout<<endl;
    delete_key(root, 50);
    preorder(root); cout<<endl;
    delete_key(root, 40);
    preorder(root); cout<<endl;
    return 0;
}
