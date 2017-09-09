// finding the LCA of the given nodes

#include<iostream>
#include<cstdio>

using namespace std;

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

int main(){
  node* root = NULL;
  node* findLCA(node*, node*, node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  node *a = root->leftChild->leftChild, *b = root->rightChild;
  node* result = findLCA(root,a,b);
  if(result){
    cout<<result->key<<"\n";
  }
  else printf("no result is found");
  return 0;
}

node* findLCA(node* root,node* a, node* b){
  if(!root) return NULL;
  else{
    if(root == a || root == b) return root;
    else{
      node* left = findLCA(root->leftChild,a,b);
      node* right = findLCA(root->rightChild,a,b);
      if(left && right) return root;
      else return (left? left:right);
    }
  }
}
