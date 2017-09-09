// Make a mirror image of the tree

#include<iostream>
#include<cstdio>

using namespace std;

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

void inOrderTraversal(node* root){
  if(root){
    inOrderTraversal(root->leftChild);
    cout<<root->key<<" ";
    inOrderTraversal(root->rightChild);
  }
}

int main(){
  node* root = NULL;
  node* allias = NULL;
  node* addChild(int);
  void makeAllias(node**,node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  makeAllias(&allias,root);
  inOrderTraversal(allias);
  return 0;
}

node* addChild(int key){
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

void makeAllias(node** allias,node* root){
  if(!root) return;
  else{
    if(!*allias){
      *allias = addChild(root->key);
    }
    node *s = *allias;
    if(root->leftChild) s->rightChild = addChild(root->leftChild->key);
    if(root->rightChild) s->leftChild = addChild(root->rightChild->key);
    makeAllias(&s->rightChild,root->leftChild);
    makeAllias(&s->leftChild,root->rightChild);
  }
}
