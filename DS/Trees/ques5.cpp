// PostOrder Traversal Recursive

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

using namespace std;

node* addChild(int key){
  node* p = new node;
  if(p){
    p->key = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
  }
  return p;
}

void postOrderTraversal(node* root){
  if(root){
    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    cout<<root->key<<" ";
  }
}
int main(){
  node* root = NULL;
  root = addChild(8);
  root->leftChild = addChild(1);
  root->rightChild = addChild(0);
  root->leftChild->leftChild = addChild(6);
  root->leftChild->rightChild = addChild(12);
  root->rightChild->leftChild = addChild(71);
  root->rightChild->rightChild = addChild(21);
  postOrderTraversal(root);
  return 0;
}
