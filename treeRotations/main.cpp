#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct treeNode{
    int key;
    treeNode* leftChild;
    treeNode* rightChild;
    int height;
};

int main()
{
    void add(treeNode**,int);
    void checkAVL(treeNode**);
    void show(treeNode**);
    treeNode* root = new treeNode;
    if(root){
        add(&root,5);
        add(&root,4);
        add(&root,2);
        add(&root,7);
        add(&root,9);
        add(&root,8);
        add(&root,0);
        add(&root,1);
        show(&root);
        checkAVL(&root);
    }
    else{
    cout<<"Memory coudn't be alloted";
    }
    return 0;
}
void add(treeNode** root,int key){
    int height(treeNode**),lHeight=0,rHeight=0;
    void rrRotate(treeNode**),rlRotate(treeNode**),llRotate(treeNode**),lrRotate(treeNode**);
    treeNode* rootA = *root;
    treeNode* block = new treeNode;
    if(block && !rootA){
        block->key = key;
        block->leftChild = NULL;
        block->rightChild = NULL;
        block->height = 0;
        rootA = block;
        *root = rootA;
        printf("added %d in the tree \n",rootA->key);
        return;
    }
    else if (!block){
    cout<<"memory overflow, could add "<<key<<" in the tree\n";
    return;
    }
    if(rootA){
        if(rootA->key >key){
            printf("Calling left because %d is greater than %d\n",rootA->key,key);
            getchar();
            add(&rootA->leftChild,key);

        }
        else{
            printf("Calling right because %d is lower than or equal to %d\n",rootA->key,key);
            getchar();
            add(&rootA->rightChild,key);

        }
        lHeight = height(&rootA->leftChild);
        rHeight = height(&rootA->rightChild);
        rootA->height = max(lHeight,rHeight) + 1;
        if(abs(lHeight-rHeight)>1){
            if(rHeight>lHeight){
                if(height(&rootA->rightChild->rightChild) > height(&rootA->rightChild->leftChild)) llRotate(&rootA);
                else lrRotate(&rootA);
            }
            else{
                if(height(&rootA->leftChild->leftChild) > height(&rootA->leftChild->rightChild)) rlRotate(&rootA);
                else rlRotate(&rootA);
            }
        }
        *root = rootA;
    }
    cout<<"End of add for key "<<key<<"\n";
}
void checkAVL(treeNode** root){

    return;
}

void show(treeNode** root){
    treeNode* rootA = *root;
    if(rootA){
        printf("Going left of %d \n",rootA->key);
        show(&rootA->leftChild);
        printf("%d \n",rootA->key);
        printf("going right of %d \n",rootA->key);
        show(&rootA->rightChild);
    }
}

int height(treeNode** root){
    treeNode* rootA = *root;
    if(!rootA){
    return -1;
    }
    else{
        rootA->height = max(height(&rootA->leftChild),height(&rootA->rightChild)) + 1;
        cout<<"Height of "<<rootA->key<<" is "<<rootA->height<<"\n";
        return rootA->height;
    }
}
void rrRotate(treeNode** root){
    treeNode *rootA = *root;
    treeNode *leftChild = rootA->leftChild;
    rootA->leftChild = leftChild->rightChild;
    leftChild->rightChild = rootA;
    *root = leftChild;
}

void llRotate(treeNode** root){
    treeNode *rootA = *root;
    treeNode *rightChild = rootA->rightChild;
    rootA->rightChild = rightChild->leftChild;
    rightChild->leftChild = rootA;
    *root = rightChild;
}

void lrRotate(treeNode** root){
    treeNode *rootA = *root;
    treeNode *rightChild = rootA->rightChild;
    rrRotate(&rightChild);
    rootA->rightChild = rightChild->leftChild;
    rightChild->leftChild = rootA;
    *root = rightChild;
}
void rlRotate(treeNode** root){
    treeNode *rootA = *root;
    treeNode *leftChild = rootA->leftChild;
    llRotate(&leftChild);
    rootA->leftChild = leftChild->rightChild;
    leftChild->rightChild = rootA;
    *root = leftChild;
}
