// Queue formation

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};

using namespace std;

int main(){
  node *front = NULL,*rear = NULL;
  void add(node**, node**, int);
  add(&front,&rear,73);
  add(&front,&rear,30);
  add(&front,&rear,94);
  add(&front,&rear,24);
  add(&front,&rear,12);
  add(&front,&rear,53);
  add(&front,&rear,34);
  add(&front,&rear,32);
  node* allias = front;
  while(allias){
    cout<<allias->key<<" ";
    allias=allias->next;
  }
  return 0;
}

void add(node** front,node **rear, int key){
  node* p = new node;
  if(!p){
    cout<<"No memory is allowed in the formation\n";
  }
  else{
    p->key = key;
    p->next = NULL;
    if(!*front){
      cout<<"value added first "<<key<<"\n ";
      *front = p;
      *rear = p;
    }
    else{
      node *r = *rear;
      r->next = p;
      r=r->next;
      *rear = r;
    }
  }
}
