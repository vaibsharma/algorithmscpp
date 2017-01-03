#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node{
    int key;
    struct node* next;
};

int main()
{
    node* top = NULL;
    void add(int,node**);
    void pop(node**);
    int ans = 1,num=0;
    add(3,&top);
    add(4,&top);
    add(7,&top);
    add(5,&top);
    add(9,&top);
    add(0,&top);

    while(ans){
        node* allias = top;
        while(allias != NULL){
            printf("%d -> ",allias->key);
            allias = allias->next;
        }
        printf("1. for add\n2. for delete\n0. to stop\n\n Please enter your choice");
        scanf("%d",&ans);
        if(ans == 1){
            printf("\n Enter the number you want to add :");
            scanf("%d",&num);
            add(num,&top);
        }
        else if(ans == 2){
            pop(&top);
        }
        else {
            printf("Program ended!");
            break;
        }

    }
    return 0;
}

void add(int key,node** t){
    node* block = new node;
    if(block == NULL) {
        printf("\nStack overflow\n");
        getchar();
        exit(0);
    }
    node* allias = *t;
    block->key = key;
    block->next = allias;
    *t = block;
}

void pop(node** top){
    node* allias = *top;
    if(allias == NULL){
        printf("\nstack is empty");
        return;
    }
    *top = allias->next;
    free(allias);
}
