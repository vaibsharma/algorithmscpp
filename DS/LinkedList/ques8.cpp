// finding the intersecting point of two joining linkedList

#include<iostream>
#include<cstdio>
#include<stack>
struct node{
  int key;
  node* next;
};

using namespace std;
int main(){
  node *a = NULL,*b = NULL,*common = NULL;
  stack<int> stackA,stackB;
  void add(node**,int);
  add(&common,82);
  add(&common,1);
  add(&common,0);
  add(&common,12);
  add(&common,31);

  add(&a,7);
  add(&a,8);
  add(&a,43);
  add(&a,23);

  add(&b,32);
  add(&b,92);
  add(&b,19);

  
  node *x = a;
  while(x->next) x = x->next;

  if(!x->next){
    x->next = common;
  }
  x = b;
  while(x->next) x = x->next;

  if(!x->next){
    x->next = common;
  }
  x=a;
  while(x)
    {
      stackA.push(x->key); 
      x = x->next;
    }
  x = b;
  while(x){
    stackB.push(x->key);
    x = x->next;
  }
  int l = stackA.size(), r = stackB.size(), last = -1, q, w;
  for(int x=0; x<min(l,r); x++){
    q = stackA.top(), w = stackB.top();
    if(q != w){
      printf("common Point is %d",last);
      break;
    }
    stackA.pop();
    stackB.pop();
    last = q;
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
    cout<<k<<" ";
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
    cout<<"\n";
    return;
  }
}
