#include <iostream>
#include <cstdio>
#include<cstdlib>

using namespace std;

struct node{
    int key;
    struct node* left_child = NULL;
    struct node* right_child = NULL;
};

struct snode{
    struct snode* next = NULL;
    struct node* mainnode = NULL;
};
int main()
{

    node* add(int);
    void IOTWR(node*);
    node* root = add(1);
    root->left_child = add(2);
    root->right_child = add(3);
    root->left_child->left_child = add(4);
    root->left_child->right_child = add(5);
    root->right_child->left_child = add(6);
    root->right_child->right_child = add(7);

    IOTWR(root);

    return 0;
}

node* add(int a){
    node* block = new node ;
    block->key = a;
    block->next = NULL;
    if(block){
        return block;
    }
    else{
        printf("stack overflow");
        exit(0);
    }

}

void IOTWR(node* root){
    int flag = 1;
    void addstack(snode**,node*);
    node* pop(snode**);
    if(root != NULL){
        node* allias = root;
        snode* stAck ;
        while(allias){
            printf(" yo ");
                addstack(&stAck,allias);
                printf("%d added in the stack \n",allias->key);
                allias = allias->left_child;
                while(!allias and flag){
                    //printf("fuck off");
                    if(stAck != NULL){

                    allias = pop(&stAck);
                    if(allias){
                        printf("%d ->",allias->key);
                        getchar();
                        allias = allias->right_child;
                    }
                    else{
                        printf("we builded the stack");
                    }
                }
                else{
                    printf("stackunder flow");
                    getchar();
                }

                    //flag = 0;
                }
            }

    }
    else{
        printf("No data structure is found");
    }
}



void addstack(snode** top,node* root){
        snode* allias = *top;
        snode* block = new snode;
        block->mainnode = root;
        block->next = allias;
        *top = block;
}

node* pop(snode** t){
    bool isEmpty(snode*);
    if(!isEmpty(*t)){
        snode* top = *t ;
        node* block = NULL;
        *t = top->next ;
        if(top->next->)
        block = top->mainnode;
        printf("\nremoved %d\n",top->mainnode->key);
        free(top);
        return block;

    }

    else{
        printf("Stackoverflow");
        getchar();
        exit(0);
        }

}

bool isEmpty(snode* s){
    if(s == NULL){
        printf("stack is now empty");
        getchar();
        exit(0);

    }
    else if(s->next == NULL){
        printf(" ->  %d ",s->mainnode->key);
        getchar();
        return true;
}
    else {
    return false;
    }
}
