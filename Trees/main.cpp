#include <iostream>
#include <bitset>
#include <cstdio>

struct node{
int value;
struct node* next;
};

using namespace std;

int main()
{
    // cout << "Hello world!" << endl;
    void add(struct node*,int);
    node* reverse(struct node*);
    struct node* ds = new node ;
    ds->value = 4 ;
    ds->next = NULL ;
    add(ds,3);
    add(ds,9);
    add(ds,5);
     add(ds,1);
     ds = reverse(ds);
    // add(ds,8);
    // add(ds,4);
    // printf(" line 23 %d",ds->value);
    struct node* point = ds;
    while(point){
        printf(" the no is ithis %d\n",point->value);
        point = point->next ;
    }
    // printf("%d hello\n",point->value);
    // delete(ds);
    return 0;
}

void add(struct node* newstr,int a)
{
    struct node* newptr = new node ;
    newptr->value = a ;
    newptr->next = NULL ;
    struct node* ptr = newstr;
    while(ptr->next){
    	// printf("%d hello\n",ptr->value);
    	ptr = ptr->next;

    }
    ptr->next = newptr;
    newstr = ptr;
    // cout<<"Hello";
}

node* reverse(struct node* ptr){
	node *point,*x;
	if(ptr->next){
		// point = ptr->next;
		// x = point;
		// point = point->next;
		// x->next = ptr;
		// ptr->next =NULL;
		// ptr->next = x;
		x =ptr->next;
		point = x->next;
		x->next = ptr;
		ptr->next = NULL;
		ptr = x;

	}

	while(point){
			// cout<<"\n point";
		x = point;
		point = x->next;
		x->next = ptr;
		ptr=x;
	}
	// x =ptr;
	// while(x){
	// 	printf("next node is %d \n",x->value);
	// 	x = x->next;
	// }

	return ptr;
}



