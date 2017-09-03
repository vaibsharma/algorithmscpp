/**
 * Given a linkedList with the even and odd numbers
 * Now create an algorithm for making changes in the
 * list so that all the even numbers are shown first
 * on iteration
 * Microsoft -> DTU 2017 internship
 */

#include<iostream>
#include<cstdio>

struct node{
  int key;
  node* next;
};

using namespace std;

int main(){
  void add(node**,int);
  void makeChange(node**);
  node* start = NULL;
  add(&start,7);
  add(&start,8);
  add(&start,43);
  add(&start,23);
  add(&start,82);
  add(&start,1);
  add(&start,0);
  add(&start,12);
  add(&start,31);
  makeChange(&start);
  node* p = start;
  while(p){
    cout<<p->key<<" ";
    p=p->next;
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

void makeChange(node** start){
  node *allias = *start,*even=NULL,*odd=NULL,*etail=NULL,*otail=NULL;
  //void swap(node**,node**);
  while(allias){
    if(allias->key%2==0){
      if(!even){
        even = allias;
        etail = allias;
      }
      else{
        etail->next = allias;
        etail = etail->next;
      }
      allias = allias->next;
      etail->next = NULL;
    }
    else{
      if(!odd){
        odd = allias;
        otail = allias;
      }
      else{
        otail->next = allias;
        otail = otail->next;
      }
      allias = allias->next;
      otail->next = NULL;
    }
  }
  etail->next = odd;
  *start = even;
}
