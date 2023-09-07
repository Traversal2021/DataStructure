#include<stdlib.h>
#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right; 
};

// New node creation
struct node* newNode(int data){
    struct node* node  = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//Traverse Preorder: visit root node - all left subtree - all right subtree
void traversePreOrder (struct node* root){
    if( root != NULL){
        cout << root->data << endl;
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

//Traverse Inorder: visit all left subtree - root node - all right subtree 
void traverseInOrder(struct node* root){
    if( root != NULL){
        traverseInOrder(root->left);
        cout << root->data << endl;
        traverseInOrder(root->right);
    }

}

// Traverse Postorder: visit all left subtree - all right subtree - root node
void traversePostOrder(struct node* root){
    if( root != NULL){
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << endl;
    }

}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);

  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}