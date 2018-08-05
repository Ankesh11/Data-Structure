#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node *parent;
};
node* make_new_node(int key, node *parent=NULL){
    node *newnode = new node();
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = parent;
    return newnode;
}
//recursive method
node *insert(node *root, int key, node *parent){
    if(root==NULL){
        node *newnode = make_new_node(key, parent);
        root = newnode;
    }
    else if(key<=root->data){
        root->left = insert(root->left, key, root);
    }
    else{
        root->right = insert(root->right, key, root);
    }
    return root;
}
//iterative method
node *insert(node *root, int key){
    node *newnode = make_new_node(key);
    node *y = NULL;
    node *x = root;
    while(x!=NULL){
        y=x;
        if(key<=x->data)
            x = x->left;
        else
            x = x->right;
    }
    newnode->parent = y;
    if(y==NULL){
        root = newnode;
        return root;
    }
    else if(newnode->data<=y->data)
        y->left = newnode;
    else
        y->right = newnode;
    return root;
}
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node *search(node *root, int key){
    if(root==NULL || root->data == key)
        return root;
    else if(key<=root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
node *minimum(node *root){
    if(root->left==NULL)
        return root;
    return minimum(root->left);
}
node *maximum(node *root){
    if(root->right==NULL)
        return root;
    return maximum(root->right);
}
node *successor(node *root){
    if(root->right!=NULL)
        return minimum(root->right);
    node *temp = root->parent;
    while(temp!=NULL && root==temp->right){
        root = temp;
        temp = temp->parent;
    }
    return temp;
}
node *predecessor(node *root){
    if(root->left!=NULL)
        return maximum(root->left);
    node *temp = root->parent;
    while(temp!=NULL && root == temp->left){
        root = temp;
        temp = temp->parent;
    }
    return temp;
}
node *transplant(node *root, node *u, node *v){
    if(u->parent==NULL)
        root = v;
    else if(u==(u->parent)->left)
        (u->parent)->left = v;
    else
        (u->parent)->right = v;
    if(v!=NULL)
        v->parent = u->parent;
    return root;
}
node *delete_node(node *root, node *z){
    if(z->left==NULL)
        transplant(root, z, z->right);
    else if(z->right==NULL)
        transplant(root, z, z->left);
    else{
        node *y = minimum(z->right);
        if(y->parent != z){
            transplant(root, y, y->right);
            y->right = z->right;
            (y->right)->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        (y->left)->parent = y;
    }
    return root;
}
int main(){
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 6);
    root = insert(root, 18);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 17);
    root = insert(root, 20);
    root = insert(root, 13);
    root = insert(root, 9);
    node *temp = search(root, 18);
    cout<<(temp->parent)->data<<endl;
    root = delete_node(root, temp);
    temp = search(root, 20);
    cout<<(temp->parent)->data<<endl;
    inorder(root);
    return 0;
}
