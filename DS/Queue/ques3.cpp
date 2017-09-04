// implementaion of queue using two stacks

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};

struct stack{
  node* top;
  node* rear;
};

struct queue{
  stack s1;
  stack s2;
};

using namespace std;

void insertion(queue** qu,int key){
  node* p = new node;
  queue* q= *qu;
  if(!p){
    cout<<"Memory is not assigned";
  }
  else{
    p->key = key;
    p->next = NULL;
    if(!q->s1.top){
      q->s1.top = p;
      q->s1.rear = p;
    }
    else{
      node* allias = q->s1.top;
      q->s1.top = p;
      q->s1.top->next = allias;
    }
  }
  cout<<"Element inserted is "<<key<<"\n";
}


int pop(queue** qu){
  queue* q = *qu;
  if(!q->s2.top){
    while(q->s1.top){
      node *allias = q->s1.top->next;
      if(!q->s2.top){
        q->s2.top = q->s1.top;
        q->s2.rear = q->s1.top;
        q->s2.top->next = NULL;
        q->s2.rear->next = NULL;
      }
      else{
        node *s2 = q->s2.top;
        q->s2.top = q->s1.top;
        q->s2.top->next = s2;
      }
      q->s1.top = allias;
      if(!q->s1.top) q->s1.rear = NULL;
    }
  }
  if(q->s2.top){
    int d = q->s2.top->key;
    q->s2.top = q->s2.top->next;
    //if(q->s2.top) cout<<"after poping the pointer is at "<<q->s2.top->key<<"\n";
    return d;
  }
  else{
    return 0;
  }
}

int main(){
  queue *q = new queue;
  q->s1.top = NULL;
  q->s1.rear = NULL;
  q->s2.top = NULL;
  q->s2.rear = NULL;
  insertion(&q,8);
  insertion(&q,38);
  insertion(&q,9);
  insertion(&q,56);
  insertion(&q,42);
  cout<<"popped element -> "<<pop(&q)<<"\n";
  cout<<"popped element -> "<<pop(&q)<<"\n";
  insertion(&q,10);
  cout<<"popped element -> "<<pop(&q)<<"\n";
  return 0;
}
