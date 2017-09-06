// Recursive Inorder Traversal

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* leftChild;     // Please make sure you write children in trees
  node* rightChild;    // forget about next pointer in trees
};

using namespace std;

int main(){
  node* root = NULL;
  node* addChild(int);
  void inOrderTraversal(node*);
  root = addChild(3);
  root->leftChild = addChild(2);
  root->rightChild = addChild(7);
  root->leftChild->leftChild = addChild(01);
  root->leftChild->rightChild = addChild(21);
  root->rightChild->leftChild = addChild(43);
  root->rightChild->rightChild = addChild(91);
  inOrderTraversal(root);
  return 0;
}

node* addChild(int key){
  node* p = new node;
  if(p){
    p->key = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
  }
  else cout<<"Memory is not allocated";
  return p;
}

void inOrderTraversal(node* root){
  if(root){
    inOrderTraversal(root->leftChild);
    cout<<root->key<<" ";
    inOrderTraversal(root->rightChild);
  }
}
