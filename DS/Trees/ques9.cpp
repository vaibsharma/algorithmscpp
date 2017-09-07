// Add child in the binary tree

#include<iostream>
#include<cstdio>
#include<cmath>

struct node{
  int key;
  node* leftChild;
  node* rightChild;
};

struct queue{
  node* child;
  queue* next;
};

using namespace std;

void addInQueue(queue** s,node* child){
  queue* st = new queue;
  if(!st){
    cout<<"No memory is assigned\n";
  }
  else{
    queue *a = *s;
    st->child = child;
    st->next = NULL;
    if(!a){
      *s = st;
    }
    else{
      while(a->next){
        a = a->next;
      }
      a->next = st;
    }
  }
}

node* deQueue(queue** s){
  if(s){
    queue *st = *s;
    node* child = st->child;
    *s = st->next;
    delete st;
    return child;
  }
  else{
    printf("Queue is already empty\n");
  }
}

int main(){
  node* root = NULL;
  node* addChild(int);
  void addElement(int,node*);
  void inOrderTraversal(node*);
  root = addChild(7);
  root->leftChild = addChild(3);
  root->rightChild = addChild(1);
  root->rightChild->leftChild = addChild(9);
  root->rightChild->rightChild = addChild(12);
  root->leftChild->rightChild = addChild(21);
  root->leftChild->leftChild = addChild(23);
  addElement(71,root);
  inOrderTraversal(root);
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

void addElement(int key,node* root){
  queue *s = NULL;
  addInQueue(&s,root);
  while(s){
    node* root = deQueue(&s);
    if(!root) cout<<"hey";
    if(root){
      if(root->leftChild) {
        cout<<"added "<<root->leftChild->key<<"\n";
        addInQueue(&s,root->leftChild);
      }
      else{
        root->leftChild = addChild(key);
        return ;
      }
      if(root->rightChild) {
        cout<<"added "<<root->rightChild->key<<"\n";
        addInQueue(&s,root->rightChild);
      }
      else{
        root->rightChild = addChild(key);
        return;
      }
    }
  }
}

void inOrderTraversal(node* root){
  if(root){
    inOrderTraversal(root->leftChild);
    printf("%d ",root->key);
    inOrderTraversal(root->rightChild);
  }
}
