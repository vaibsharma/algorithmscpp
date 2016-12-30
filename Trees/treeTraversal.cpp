#include<iostream>
#include<cstdio>

struct node{
    int key;
    struct node* left_child = NULL;
    struct node* right_child = NULL;
};

using namespace std;

int main(){
    node* add(int);
    void preorderTraversal(node*);
    void postorderTraversal(node*);
    node* root = new node ;
    root = add(3);
    root->left_child = add(4);
    root->right_child = add(2);
    root->left_child->left_child = add(1);
    root->left_child->right_child = add(8);
    root->right_child->left_child = add(3);

	printf("\t *** PREORDER TRAVERSAL ***\n\n");
    preorderTraversal(root);

	printf("\n\t *** POSTORDER TRAVERSAL ***\n\n");
    postorderTraversal(root);

return 0;
}

node* add(int a){
    struct node* block = new node ;
    block->key = a;
    return block ;
}

void preorderTraversal(node* root){
    if(root){
        printf("%d -> ",root->key);
        if(root->left_child){
        preorderTraversal(root->left_child);
        }
        if(root->right_child){
        preorderTraversal(root->right_child);
        }

    }
}

void postorderTraversal(node* root){
    if(root){
        if(root->left_child){
        postorderTraversal(root->left_child);
        }
        if(root->right_child){
        postorderTraversal(root->right_child);
        }
        printf("%d -> ",root->key);
    }
}
