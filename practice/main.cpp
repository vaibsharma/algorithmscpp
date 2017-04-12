#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int value = 0;
    struct node *next = NULL;
};
int main()
{   void add(int,node**,node**);
    void linkedListSort(node** , node**);
    printf("lets make a linked list");
    node *head = NULL,*tail = NULL;
    add(3,&head,&tail);
    add(4,&head,&tail);
    add(1,&head,&tail);
    add(6,&head,&tail);
    add(3,&head,&tail);
    add(7,&head,&tail);
    add(32,&head,&tail);
    add(46,&head,&tail);
    add(34,&head,&tail);
    add(0,&head,&tail);
    add(1,&head,&tail);
    add(9,&head,&tail);
    node* iter = tail;
    while(iter){
        cout<<iter->value<<" ";
        iter=iter->next;
    }
    linkedListSort(&head,&tail);
    return 0;
}
void add(int key,node** head,node** tail){
    struct node* block = new node,*hAllias = *head;

    block->value = key;
    block->next = NULL;
    if(!block){
        cout<<"Memory can't be assigned currently";
        return;
        }
        if(block && *head){
            hAllias->next = block;
            hAllias =hAllias->next;
            *head = hAllias;
        }
        else{
            *head = block;
            *tail = block;
        }
}

void linkedListSort(node** head,node** tail){
    void callSort(node**,node**,int);
    int length = 0,half=0;
    node* iter = *tail;
    while(iter){
        length++;
        iter = iter->next;
    }
    half = length/2;
    callSort(head,tail,half);

}
                                                                                     *tail = hallias;
            *head = tallias;
        }
    }
    if(tail* != *head){
        node* current = *tail;
        while(now<=half){
        current= current->next;
        now++;
        }
    }
    callSort(head,&current,half/2);
    callSort(&current->next,tail,half/2);
    mergeLink(head,&current,tail);

}
