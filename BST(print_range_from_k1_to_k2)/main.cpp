#include <iostream>
#include <cstdio>

using namespace std;
struct BST{
    int key;
    BST* left_child;
    BST* right_child;
};
int main()
{
    void add(int,BST**);
    void show(BST**);
    void showInIncreasing(BST**,int,int);
    BST* root = new BST;
    add(4,&root);
    add(1,&root);
    add(5,&root);
    add(3,&root);
    add(8,&root);
    add(9,&root);
    add(2,&root);
    add(12,&root);
    add(6,&root);
    add(7,&root);

    show(&root);
    showInIncreasing(&root,1,12);
    return 0;
}
void add(int key, BST** root){
    BST* rootA = *root;
    BST* block = new BST;
    if(block){
        block->key = key;
        block->left_child = NULL;
        block->right_child = NULL;    }
    else{
        cout<<"Memory overflow";
    return;
    }
    if(rootA){
        if(rootA->key >= key){
            add(key,&rootA->left_child);
        }
        else if(rootA->key<key){
            add(key,&rootA->right_child);
        }
    }
    else{
        rootA = block;
        *root = rootA;
        return;
    }
}

void show(BST** root){
    BST* rootA = *root;
    if(rootA){
        // printf("%d ",rootA->key);
        show(&rootA->left_child);
        show(&rootA->right_child);
    }
}
void showInIncreasing(BST** root,int k1,int k2){
    BST* rootA = *root;
   	if(!rootA){
   		return;
   	}
    if(rootA->key < k1){
        showInIncreasing(&rootA->right_child,1,12);
    }
    if(rootA->key >= k1 && rootA->key <= k2){
        showInIncreasing(&rootA->left_child,1,rootA->key);
        printf("%d ",rootA->key);
        showInIncreasing(&rootA->right_child,rootA->key,12);
    }
    if(rootA->key > k2){
        showInIncreasing(&rootA->left_child,1,12);
    }

}
