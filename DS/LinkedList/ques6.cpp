// floyd cycle algorithm implementation

#include<iostream>
#include<cstdio>
struct node{
  int key;
  node* next;
};

using namespace std;

int main(){
  void add(node**,int);
  void detectCycle(node**);
  node *start = NULL,*p = NULL, *allias;
  add(&start,7);
  add(&start,8);
  add(&start,43);
  add(&start,23);
  p = start->next->next->next;
  add(&start,82);
  add(&start,1);
  add(&start,0);
  add(&start,12);
  add(&start,31);
  allias = start;
  while(allias->next) allias = allias->next;
  allias->next = p;
  detectCycle(&start);
  return 0;
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

void detectCycle(node** start){
  node *a = *start, *b = *start;
  int count=0;
  a=a->next;
  b=b->next->next;
  while(a!=b){
    a=a->next;
    b=b->next->next;
  }
  a=*start;
  while(a!=b){
    a=a->next;
    b=b->next;
  }
  cout<<"the common point found is "<<b->key<<"\n";
  a=a->next;
  while(a!=b) {a=a->next;count++;}
  cout<<"the total length of the loop "<<count;
}
