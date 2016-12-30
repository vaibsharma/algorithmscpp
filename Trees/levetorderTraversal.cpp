
#include<iostream>
#include<cstdio>

using namespace std;

struct node{
    int key;
    struct node* left_child =NULL;
    struct node* right_child = NULL;
};
int Height = 0;
int main(){
    struct node* root;
    node* add(int);
    void calHeight(node*,int);
    void levelorderTraversal(node*,int);
    root = add(3);
    root->left_child = add(4);
    root->right_child = add(2);
    root->left_child->left_child = add(1);
    root->left_child->right_child = add(8);
    root->right_child->left_child = add(3);


    calHeight(root,0); //To calculate height of the tree

    // printf("Height %d\n",Height);

    for(int x = 1; x<=Height;x++){           // Iterating to all the levels one by one
        levelorderTraversal(root,x);
        }


    return 0;
}

node* add(int a){
    struct node* block = new node;
    block->key = a;
    return block;
}

void levelorderTraversal(node* root, int level){
	// printf("level %d\n",level);
        if(level == 1){
            printf("%d ",root->key);
        }
        else{
            if(root->left_child) levelorderTraversal(root->left_child,level-1);
            if(root->right_child) levelorderTraversal(root->right_child,level-1);
        }
    }

void calHeight(node *x,int height){
    if(x){
        height++;
        if(height>Height) Height = height;
        if(x->left_child) calHeight(x->left_child,height);
        if(x->right_child) calHeight(x->right_child,height);
    }
}
