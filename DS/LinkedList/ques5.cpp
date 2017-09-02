/**
 * Does the linkedList has loops?
 */

#include<iostream>
#include<cstdio>
#include<unordered_map>

struct node{
  int key;
  node* next;
};

using namespace std;
int main(){
  node* start = NULL;
  unordered_map <node**,bool> hash;
  void add(node**, int);
  add(&start,5);
  add(&start,6);
  add(&start,9);
  node* k=start->next->next;
  add(&start,10);
  k->next->next=k;
  node* allias = start;
  while(start){
    if(!hash[&(allias->next)]){
      hash[&(allias->next)] = true;
      cout<<allias->key<<" ";
      allias=start->next;
      start=allias;
    }
    else{
      cout<<"found the loop";
      cout<<allias->key<<" ";
      break;
    }
  }
  return 0;
}

void add(node** start,int x){
  node* allias = *start;
  node* p = new node;
  if(!p){
    cout<<"Memory is not allocated";
  }
  else{
    p->key = x;
    p->next = NULL;
    if(!allias){
      *start = p;
    }
    else{
      while(allias){
        if(allias->next){
          allias=allias->next;
        }
        else{
          allias->next = p;
          break;
        }
      }
    }
  }
}
