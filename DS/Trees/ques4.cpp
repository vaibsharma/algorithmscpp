// Inorder Traversal iterative

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

struct stack{
  node* child;
  stack* next;
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

void push(stack** st, node* child){
  stack *s = new stack;
  s->next = *st;
  s->child = child;
  *st = s;
}

node* pop(stack** st){
  stack * s = *st;
  node* child = NULL;     
  if(s){
    child = s->child;
    s = s->next;
    *st = s;              // You made mistake here
  }
  return child;
}

void inOrderTraversal(node* root){
  stack *st = NULL;
  while(root){
    push(&st,root);
    root=root->leftChild;
    if(!root){
      while(!root && st){
        root = pop(&st);
        if(root){
          cout<<root->key<<" ";
          root = root->rightChild;
        }
      }
    }
  }
}

int main(){
  node* root = NULL;
  root = addChild(4);
  root->leftChild = addChild(5);
  root->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(9);
  root->leftChild->leftChild = addChild(19);
  root->rightChild->leftChild = addChild(17);
  root->rightChild->rightChild = addChild(14);
  inOrderTraversal(root);
  return 0;
}
