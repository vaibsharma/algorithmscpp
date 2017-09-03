// Get a element of linkedList in O(1) complexity

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
  p = start;
  while(p->next) p = p->next;
  p->next = start;
  p = start;
  int count=1;
  while(p!=p->next){
    if(count%4==0){
      allias = p->next->next;
      p->next->next = NULL;
      p->next = allias;
    }
    else p=p->next;

    count++;
  }
  cout<<"The last element is "<<p->key;


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
