// find the sum of a level in a tree
#include<iostream>
#include<cstdio>
#include<queue>
struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

using namespace std;

int main(){
  node* root = NULL;
  node* addChild(int);
  int findMaxLevelSum(node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  cout<<"The maximum sum is "<<findMaxLevelSum(root);
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

int findMaxLevelSum(node* root){
  queue<node*> q;
  int sum = 0,highest = 0;
  q.push(root);
  sum+=root->key;
  q.push(NULL);
  if(sum>highest) highest = sum;
  sum=0;
  while(!q.empty()){
    root = q.front();
    q.pop();
    if(root){
      sum+=root->key;
      if(root->leftChild) q.push(root->leftChild);
      if(root->rightChild) q.push(root->rightChild);
    }
    else{
      if(highest < sum) highest = sum;
      sum = 0;
      if(!q.empty()) q.push(NULL);
    }
  }
  return highest;
}
