#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct node{
    int key;
    struct node* left_child = NULL;
    struct node* right_child = NULL;
          int height = 0 ;
};

int Diameter = 0 ;

int main()
{

    node* add(int);
    void calDiameter(node*);

    node* root ;
    root = add(3);
    root->left_child = add(4);
    root->right_child = add(2);
    root->left_child->left_child = add(1);
    root->left_child->right_child = add(8);
    root->right_child->left_child = add(3);
    root->right_child->left_child->left_child = add(6);
    root->right_child->left_child->right_child = add(31);
    root->right_child->left_child->right_child->right_child = add(34);
    root->left_child->right_child->left_child = add(48);
    root->left_child->right_child->left_child->right_child = add(-21);
    root->left_child->left_child->left_child = add(-9);
    root->left_child->left_child->left_child->left_child = add(283);


    calDiameter(root);
    cout<<"Diameter of this tree is "<<Diameter ;

    return 0 ;
}

node* add(int a){
    struct node* block = new node;
    block->key = a;
    return block;
}

void calDiameter(node* root){
    void recursiveDiameter(node*);
    recursiveDiameter(root);
}

int recursiveDiameter(node* root){
    int height = 0;
    int diameter = 0;
    int leftHeight = 0;
    int rightHeight = 0;

    if(!root){
        return 0;
        }
    if(root->left_child == NULL || root->right_child == NULL){
            leftHeight = recursiveDiameter(root->left_child) ;
            rightHeight = recursiveDiameter(root->right_child) ;
            height = max(leftHeight,rightHeight) +1;
            root->height = height;
            diameter = leftHeight + rightHeight + 1;
        }
    if(root->left_child && root->right_child){
            if(!root->height){
                    leftHeight = recursiveDiameter(root->left_child);
                    rightHeight = recursiveDiameter(root->right_child);
                    height = max(leftHeight,rightHeight) + 1;
                    root->height = height;
                    diameter = leftHeight + rightHeight +1 ;
                }

        }
    printf("The root is : %d \n \t\t Diameter is : %d \n \t\t The height is : %d\n\n\n",root->key,diameter,height);
     if( Diameter < max(height,diameter)) Diameter = max(height,diameter);
    return height;
}
