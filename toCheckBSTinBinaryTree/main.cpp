#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
struct node{
    int key;
    int High ;
    int Low  ;
    struct node* left_child;
    struct node* right_child;
    };

int checkHigh(node*,int);
int checkLow(node*,int);
int main()
{
    node* add(int);
    int check(node*);
    node* root = add(1);
    root->left_child = add(-1);
    root->right_child = add(3);
    root->left_child->left_child = add(-4);
    root->left_child->right_child = add(1);
    root->left_child->left_child->left_child = add(-5);
    root->left_child->left_child->right_child = add(0);
    root->right_child->left_child = add(2);
    root->right_child->right_child = add(5);
    root->right_child->right_child->left_child = add(4);
    root->right_child->right_child->right_child = add(6);

    if(check(root)){
        printf("This tree is a BST");
    }
    else{
        printf("Opps its not a BST");
    }

    return 0;
}

node* add(int a){
    node* block = new node;
    block->key = a;
    block->High = a;
    block->Low = a;
    block->left_child = NULL;
    block->right_child = NULL;
    return block ;
}

int check(node* root){

        if(!root){
            return 1;
        }
        else{
                int high,low;
                high = checkHigh(root->left_child,root->key);
                low = checkLow(root->right_child,root->key);
                root->High = max(max(high,low),root->key);
                root->Low = min(min(high,low),root->key);
                if(high <= root->key && low >= root->key) {
                     printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
                     return 1;
                }
                else{
                    printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
                    return 0;
                }
        }

    }

int checkHigh(node* root,int a){
    if(root != NULL){
        int high,low;
        high = checkHigh(root->left_child,root->key);
        low = checkLow(root->right_child,root->key);
        root->High = max(max(high,low),root->key);
        root->Low = min(min(high,low),root->key);
        if(high <= root->key && low >= root->key){
            printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
            return root->High;
            }
        else{
             printf("thus its not a bst");
             printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
             getchar();
            }
    }
    else{
        return a;
    }
}

int checkLow(node* root,int a){
    if(root != NULL){
        int high,low;
        high = checkHigh(root->left_child,root->key);
        low = checkLow(root->right_child,root->key);
        root->High = max(max(high,low),root->key);
        root->Low = min(min(high,low),root->key);
        if(high <= root->key && low >= root->key){
            printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
            return root->Low;
            }
         else{
            printf("thus its not a bst\n");
            printf("the highest node in left-> %d , lowest node in right is %d and key is %d \n",high,low,root->key);
            getchar();
            }
    }
    else return a;
}
