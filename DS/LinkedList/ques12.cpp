// Find modular node from end

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
  int findModularNode(node*);
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
  if(findModularNode(start)== 8){
    cout<<"Not found";
  }
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

int findModularNode(node* start){
  if(!start->next){
    return 0;
  }
  else{
    int x = findModularNode(start->next);
    //cout<<x<<"\n";
    if(x==-1){
      return -1;
    }
    if((x+1)%3==0){
      cout<<"Element is "<<start->key<<"\n";
      return -1;
    }
    else return 1+x;
  }
}
