// find max element without recursion

#include<iostream>
#include<cstdio>
#include<cmath>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

struct stack{
  stack* next;
  node* child;
};

using namespace std;

void addInStack(stack** s,node* child){
  stack* st = new stack;
  if(!st){
    cout<<"No memory is assigned\n";
  }
  else{
    st->child = child;
    st->next = *s;
    *s = st;
  }
}

node* pop(stack** s){
  if(s){
    stack * st = *s;
    node* child = st->child;
    *s = st->next;
    delete st;
    return child;
  }
  else{
    printf("Stack is already empty\n");
  }
}

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
  printf("%d\n",findMax(root));
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
  stack *s = NULL;
  int highest = -1000007;
  if(root){
    addInStack(&s,root);
    while(s){
      node* root = pop(&s);
      if(highest<root->key)
        highest = root->key;
      if(root->leftChild) addInStack(&s,root->leftChild);
      if(root->rightChild) addInStack(&s,root->rightChild);
    }
    return highest;
  }
  printf("Note!!! Root is not found\n");
}
