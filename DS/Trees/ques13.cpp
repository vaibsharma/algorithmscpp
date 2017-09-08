// Print all the root to leaf path

#include<iostream>
#include<cstdio>
#include<vector>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

using namespace std;

int main(){
  node* root = NULL;
  node* addChild(int);
  void printThePath(node*,vector<int>);
  vector<int> a;
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  printThePath(root,a);
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

void printThePath(node* root,vector<int> a){
  if(!root){
    for(int x=0;x<a.size();x++){
      printf("%d ",a[x]);
    }
    printf("\n");
    return;
  }
  a.push_back(root->key);
  if(root->leftChild && root->rightChild){
    printThePath(root->leftChild,a);
    printThePath(root->rightChild,a);
  }
  else printThePath(root->leftChild,a);
}
