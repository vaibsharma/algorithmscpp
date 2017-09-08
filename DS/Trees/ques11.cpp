// finding the diameter of the tree

#include<iostream>
#include<cstdio>

struct node{
  int key;
  int height;
  node* leftChild;
  node* rightChild;
};

using namespace std;

int main(){
  node* root = NULL;
  node* addChild(int);
  int updateHeight(node*);
  int findDiameter(node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  cout<<updateHeight(root)<<" ";
  cout<<findDiameter(root);
  return 0;
}

node* addChild(int key){
  node* p = new node;
  if(!p){
    cout<<"Memory is not allocated. Returning a NULL pointer\n";
  }
  else{
    p->key = key;
    p->height = 0;
    p->leftChild = NULL;
    p->rightChild = NULL;
  }
  return p;
}

int updateHeight(node* root){
  if(!root) return 0;
  if(root->height == 0){
      int height = max(updateHeight(root->leftChild),updateHeight(root->rightChild));
      root->height = height+1;
      cout<<"the height for "<<root->key<<" is "<<root->height<<"\n";
  }
  return root->height;
}

int findDiameter(node* root){
  if(!root) return 0;
  return max(max(findDiameter(root->leftChild),findDiameter(root->rightChild)),updateHeight(root->leftChild)+updateHeight(root->rightChild)+1);
}
