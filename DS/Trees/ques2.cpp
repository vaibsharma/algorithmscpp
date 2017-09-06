// PreOrder Traversal Non Recursive

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

node* pop(stack** st){
  stack *s = *st;
  if(s){
    node* p = s->child;
    s = s->next;
    *st = s;
    return p;
  }
}

void push(stack** st,node* child){
  stack *newptr = new stack;
  if(!newptr){
    cout<<"Memory is not allocated";
  }
  newptr->child = child;
  newptr->next = *st;
  *st = newptr;
}

int main(){
  node* root = NULL;
  node* addChild(int);
  void PreOrderTraversal(node*,stack**);
  stack* s = NULL;
  root = addChild(4);
  root->leftChild = addChild(1);
  root->rightChild = addChild(71);
  root->leftChild->leftChild = addChild(7);
  root->rightChild->leftChild = addChild(12);
  root->leftChild->rightChild = addChild(32);
  root->rightChild->rightChild = addChild(31);
  PreOrderTraversal(root,&s);
  return 0;
}

node* addChild(int key){
  node *p = new node;
  if(!p){
    cout<<"No memory is allocated \n";
  }
  else{
    p->key = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
  }
  cout<<"No pointer found";
}

void PreOrderTraversal(node* root,stack** st){
  stack *s = *st;
  while(root){
    push(&s,root);
    cout<<root->key<<" ";
    root = root->leftChild;
    if(!root){
      while(!root && s){
        root = pop(&s);
        root = root->rightChild;
      }
    }
  }
}
