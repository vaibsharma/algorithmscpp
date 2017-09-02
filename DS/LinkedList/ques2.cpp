#include<iostream>
#include<cstdio>
using namespace std;
struct node{
  int key;
  node* next;
};
int main(){
  node *start = NULL,*waste=NULL;
  void add(int,node**);
  cout<<"hey its working"<<"\n";
  add(4,&start);
  add(9,&start);
  add(5,&start);
  add(7,&start);
  add(2,&start);
  cout<<"Hey its done too\n";
  while(start){
    cout<<start->key<<"\n";
    cout<<&(start)<<" ";
    waste = start;
    cout<<&(waste)<<" ";
    start = start->next;
  }
  return 0;
}

void add(int x,node** start){
  node *p = new node, *allias = *start,*s=NULL;
  s = allias;
  if(!p){
    printf("No memory alloted");
    return;
  }
  p->key = x;
  p->next = NULL;
  if(!*start){
    *start = p;
  }
  else{
    //node* allias = *start;
    while(allias->next){
      allias = allias->next;
    }
    //cout<<"did\n";
    allias->next = p;
  }
}
