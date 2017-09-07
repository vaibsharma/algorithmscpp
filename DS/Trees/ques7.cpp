// find max element
#include<iostream>
#include<cstdio>
#include<cmath>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

using namespace std;

int main(){
  node* root = NULL;
  node* addChild(int);
  int findMax(node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  cout<<findMax(root);
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

int findMax(node* root){
  if(!root){
    return -1000007;
  }
  int left = findMax(root->leftChild);
  int right = findMax(root->rightChild);
  return max(max(left,right),root->key);
}
