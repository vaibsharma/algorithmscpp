// Post Order Traversal Iterative
// Need to change it

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

struct stack{
  node* child;
  stack *next;
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
  if(s){
    s->child = child;
    s->next = *st;
    *st = s;
  }
  else printf("Stack cannot assigned value to the operator");
}

node* pop(stack** st){
  node* child = NULL;
  stack *s = *st;
  if(s){
    child = s->child;
    s = s->next;
    *st = s;
  }
  return child;
}

void postOrderTraversal(node* root){
  stack *s = NULL,right* = NULL;
  while(root){
    push(&s,root);
    root = root->leftChild;
    if(!root){
      while(!root && s){
        root = pop(&s);
        node* child = root;
        root = root->rightChild;
        if(child){
          cout<<child->key<<" ";
        }
        delete child;
      }
    }
  }
}

int main(){
  node* root = NULL;
  root = addChild(1);
  root->leftChild = addChild(2);
  root->rightChild = addChild(3);
  root->leftChild->leftChild = addChild(4);
  root->leftChild->rightChild = addChild(5);
  root->rightChild->leftChild = addChild(6);
  root->rightChild->rightChild = addChild(7);
  postOrderTraversal(root);
  return 0;
}
