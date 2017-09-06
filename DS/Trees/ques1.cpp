// Tree Traversal Question type 1
// PreOrder Traversal : Recursively

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

using namespace std;

int main(){
  node* root = NULL;
  node* returnChild(int);
  void PreOrderTraversal(node*);
  root = returnChild(7);
  root->leftChild = returnChild(3);
  root->rightChild = returnChild(1);
  root->rightChild->leftChild = returnChild(9);
  root->rightChild->rightChild = returnChild(12);
  root->leftChild->rightChild = returnChild(21);
  root->leftChild->leftChild = returnChild(23);
  PreOrderTraversal(root);
  return 0;
}

node* returnChild(int key){
  node* p = new node;
  if(!p){
    cout<<"Memory is not allocated. Returning a NULL pointer\n";
  }
  else{
    p->key = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
  }
  return p;
}

void PreOrderTraversal(node* root){
  if(!root) return;
  cout<<root->key<<" ";
  PreOrderTraversal(root->leftChild);
  PreOrderTraversal(root->rightChild);
}
