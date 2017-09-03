//print elements of linkedList from end

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};

using namespace std;

int main(){
  void add(node**, int);
  void printReverse(node*);
  node* start = NULL;

  add(&start,8);
  add(&start,23);
  add(&start,12);
  add(&start,10);
  add(&start,131);
  printReverse(start);
  return 0;
}

void add(node** start,int x){
  node* p = new node;
  if(!p){
    printf("memory not assigned");
  }
  else{
    p->key = x;
    p->next = NULL;
    if(!*start){
      *start = p;
    }
    else{
      node* allias = *start;
      p->next = allias;
      allias = p;
      *start = allias;
    }
  }
}

void printReverse(node* start){
  node* p = start;
  if(!p) return;
  else {
    printReverse(p->next);
    cout<<p->key<<" ";
  }
}
