// Implementing functioning of stack using two queues

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};

struct queue{
  node* front;
  node* rear;
};

struct stack{
  queue q1;
  queue q2;
};

using namespace std;

int pop(stack** s){
  stack* st = *s;
  if(!st->q1.front){
    while(st->q2.front!=st->q2.rear){
      if(!st->q1.front){
        st->q1.front = st->q2.front;
        st->q1.rear = st->q2.front;
      }
      else{
        st->q1.rear->next = st->q2.front;
        st->q1.rear = st->q1.rear->next;
      }
      st->q2.front = st->q2.front->next;
    }
    int d = st->q2.front->key;
    st->q2.front = NULL;
    st->q2.rear = NULL;
    return d;
  }
  else if(!st->q2.front){
    while(st->q1.front!=st->q1.rear){
      if(!st->q2.front){
        st->q2.front = st->q1.front;
        st->q2.rear = st->q1.front;
      }
      else{
        st->q2.rear->next = st->q1.front;
        st->q2.rear = st->q2.rear->next;
      }
      st->q1.front = st->q1.front->next;
    }
    int d = st->q1.front->key;
    st->q1.front = NULL;
    st->q1.rear = NULL;
    return d;
  }
}


void insertion(stack** s,int key){
  node* p = new node;
  stack* st = *s;
  if(!p){
    cout<<"No memory is alloted";
    return;
  }
  p->key = key;
  p->next = NULL;
  if(st->q1.front){
    node* c = st->q1.rear;
    c->next = p;
    c = c->next;
    st->q1.rear = c;
  }
  else if(st->q2.front){
    node* c = st->q2.rear;
    c->next = p;
    c = c->next;
    st->q2.rear = c;
  }

  if(!st->q1.front){
    st->q1.front = p;
    st->q1.rear = p;
    *s = st;
  }
  cout<<"pushed element is "<<key<<"\n";
}

int main(){
  stack* s = new stack;
  s->q1.front = NULL;
  s->q1.rear = NULL;
  s->q2.front = NULL;
  s->q2.rear = NULL;
  insertion(&s,8);
  insertion(&s,38);
  insertion(&s,9);
  insertion(&s,56);
  insertion(&s,42);
  cout<<"popped element -> "<<pop(&s)<<"\n";
  cout<<"popped element -> "<<pop(&s)<<"\n";
  insertion(&s,9);
  cout<<"popped element -> "<<pop(&s)<<"\n";
  return 0;
}
