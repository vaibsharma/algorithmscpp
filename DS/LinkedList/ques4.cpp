/**
 * Adding the node in the last of linked List
 * Finding the nth node from the last
 */

#include <iostream>
#include <cstdio>
struct node{
  int key;
  node* next;
};
using namespace std;
int main(){
  node* start = NULL;
  void add(int,node**);
  void printNthFromEnd(node*,int);
  add(4,&start);
  add(5,&start);
  add(7,&start);
  add(9,&start);
  printNthFromEnd(start,2);
  return 0;
}

void add(int x,node** start){
  node* block = new node;
  node* allias = *start;
  if(!block){
    printf("the memory is not allocated");
  }
  else{
    block->key = x;
    block->next = NULL;
    if(!allias){
      *start = block;
      return;
    }
    else{
      while(allias){
        if(allias->next){
          //cout<<allias->key<<" ";
          allias=allias->next;
        }
        else{
          allias->next = block;
          break;
        }
        cout<<"\n";
      }
    }
  }
}

void printNthFromEnd(node* start,int n){
  node* begin=start;
  int count=0;
  while(start && count<n){
    start=start->next;
    count++;
  }
  while(start){
    start=start->next;
    begin=begin->next;
  }
  cout<<begin->key;
}
