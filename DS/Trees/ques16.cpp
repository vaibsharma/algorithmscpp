// Printing the zigzag pattern element

#include<iostream>
#include<cstdio>
#include<stack>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

node* addChild(int key){
  node* p = new node;
  if(p){
    p->key = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
  }
  return p;
}
using namespace std;

int main(){
  node* root = NULL;
  void printZigzag(node*);
  root = addChild(4);
  root->leftChild = addChild(5);
  root->rightChild = addChild(8);
  root->leftChild->leftChild = addChild(1);
  root->leftChild->rightChild = addChild(0);
  root->rightChild->leftChild = addChild(31);
  root->rightChild->rightChild = addChild(12);
  printZigzag(root);
  return 0;
}

void printZigzag(node* root){
  stack<node*> s,p;
  s.push(root);
  int side = 1;
  while(!s.empty()){
    //cout<<"hey ";
    node* root = s.top();
    s.pop();
    if(root){
      printf("%d ",root->key);
      if(side){
        if(root->leftChild) p.push(root->leftChild);
        if(root->rightChild) p.push(root->rightChild);
      }
      else{
        if(root->rightChild) p.push(root->rightChild);
        if(root->leftChild) p.push(root->leftChild);
      }
    }
      if(s.empty()){
        side = 1-side;
        s=p;
        while(!p.empty()) p.pop();
      }
  }
}
