#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node{
    int key;
    node* left_child = NULL;
    node* right_child = NULL;
};

int width[100] = {0};

int main()
{
    node* root = NULL;
    int Height ;
    node* add(int);
    void widthCal(int,node*);
    int heightCal(node*);
    root = add(12);
    root->left_child  = add(3);
    root->right_child = add(2);
    root->left_child->left_child = add(1);
    root->left_child->right_child = add(4);
    root->right_child->left_child = add(0);
    root->left_child->right_child->right_child = add(12);
    root->left_child->right_child->left_child = add(10);
    root->left_child->right_child->left_child->left_child = add(10);
    root->right_child->left_child->left_child = add(21);
    Height = heightCal(root);

    printf("Height of the tree is : %d",Height);

        widthCal(0,root);

    for(int i =0; width[i] != 0; i++){
        printf("at %d level : %d ",i+1,width[i]);
    }
    return 0;
}

int heightCal(node* root){
    if(root == NULL){
        return 0 ;
    }
    return max(1+heightCal(root->left_child),1+heightCal(root->right_child));
}

node* add(int value){
    node* block = new node;
    if(block == NULL){
        printf("STACKOVERFLOW\n");
        exit(0);
    }
    block->key = value ;
    block->right_child = NULL ;
    block->left_child = NULL ;
    return block;
}

void widthCal(int i,node* root){
    if(root != NULL){
        width[i]++;
        widthCal(i+1,root->left_child);
        widthCal(i+1,root->right_child);
    }
}

