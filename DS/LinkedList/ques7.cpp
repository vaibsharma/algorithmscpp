// Reversing a linkedList

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};
using namespace std;

int main(){
  void add(node**,int);
  void reverseLinkedList(node**);
  node *start = NULL,*p = NULL, *allias;
  add(&start,7);
  add(&start,8);
  add(&start,43);
  add(&start,23);
  add(&start,82);
  add(&start,1);
  add(&start,0);
  add(&start,12);
  add(&start,31);
  allias = start;
  while(allias){
    printf("%d ",allias->key);
    allias=allias->next;
  }
  printf("\n");
  reverseLinkedList(&start);
  allias = start;
  
  return 0;
}

void reverseLinkedList(node** start){
  node *history = *start, *p = history->next,*allias = NULL;
  //history->next = NULL;
  if(history->next){
    while(p->next){
      allias = p->next;
      p->next = history;
      history = p;
      p = allias;
    }
    p->next = history;
    history = *start;
    history->next = NULL;
    *start = p;
  }
  while(p){
    if(p->next)
    printf("%d->%d\n",p->key,p->next->key);
    p = p->next;
  }
}

void add(node** start,int k){
  node* p = new node;
  if(!p){
    printf("no memory is allotted");
    return;
  }
  else{
    p->key = k;
    p->next = NULL;
    if(!*start){
      *start = p;
    }
    else{
      node* allias = *start;
      while(allias->next) allias = allias->next;
      allias->next = p;
    }
    return;
  }
}
