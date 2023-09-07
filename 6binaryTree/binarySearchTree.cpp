#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a node
struct node* newNode(int data){
    struct node* node = (struct node *)malloc(sizeof(struct node));

    node-> data = data;
    node-> left = NULL;
    node-> right = NULL;

    return node;
}


// Inorder Traversal: visit all left subtree - root node - all right subtree
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

// Insert a node
struct node* insert(struct node* root, int data){
    if(root == NULL ) return newNode(data);
    if (data > root->data ){
        root->right = insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }
    return root;
}


// Find the inorder successor
struct node* findSuccesor(struct node* tempNode){
    while(tempNode->left != NULL){
        tempNode = tempNode->left;
    }

    return tempNode;
}


// Deleting a node
struct node* deleteNode(struct node* root, int nodeData){
    if(root == NULL) return root;

    if(nodeData < root->data ) root->left = deleteNode(root->left, nodeData);
    else if(nodeData > root->data) root->right = deleteNode(root->right, nodeData);
    else{
        if ( root->left == NULL ) return root->right;
        else if( root->right == NULL  ) return root->left;
        struct node* succesor = findSuccesor(root->right);
        root->data = succesor->data;
        root = deleteNode(root, succesor->data);
    }

    return root;
}


// Driver code
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);
}