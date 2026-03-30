#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
//    int * ptr;
    struct Node * nextPtr;
};

//int * head;

struct Node * head =NULL;

int main(){

    struct Node * x= (struct Node*) malloc( sizeof(struct Node) );
    x->value=10;
    x->nextPtr=NULL;

    head=x;

    printf("value using head = %d\n",head->value);

    struct Node *y;
    y=(struct Node*) malloc( sizeof(struct Node) );
    y->value=20;
    y->nextPtr=NULL;


    struct Node *z;
    z=(struct Node*) malloc( sizeof(struct Node) );
    z->value=30;
    z->nextPtr=NULL;

    head->nextPtr=y;

    y->nextPtr=z;


    struct Node * traveller;
    traveller=head;

    printf("Traveller is at %d\n",traveller->value);

    traveller=traveller->nextPtr;

    printf("Traveller is at %d\n",traveller->value);

    printf("traveller is at the first node\n");
    traveller=head;

    while(traveller!=NULL){
        printf("Traveller is at %d\n",traveller->value);
        traveller=traveller->nextPtr;
    }

    return 0;
}
