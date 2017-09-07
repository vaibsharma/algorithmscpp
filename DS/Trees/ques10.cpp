#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

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
  void printReverse(node* root);
  root = addChild(2);
  root->leftChild = addChild(9);
  root->rightChild = addChild(4);
  root->leftChild->leftChild = addChild(10);
  root->leftChild->rightChild = addChild(12);
  root->rightChild->leftChild = addChild(20);
  root->rightChild->rightChild = addChild(19);
  printReverse(root);
  return 0;
}

void printReverse(node* root){
  stack<node*> s;
  queue<node*> q;
  q.push(root);
    while(!q.empty()){
      node* root = q.front();
      q.pop();
      s.push(root);
      if(root->leftChild) q.push(root->leftChild);
      if(root->rightChild) q.push(root->rightChild);
    }
    while(!s.empty()){
      node* root = s.top();
      s.pop();
      cout<<root->key<<" ";
    }
}
