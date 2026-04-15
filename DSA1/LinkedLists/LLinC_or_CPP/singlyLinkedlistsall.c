#include<stdio.h>

struct Node {
    int value;
    struct Node * nextPtr;
};

struct Node * head =NULL;

void insertHead(int val){
    struct Node * newNode =  malloc(sizeof(struct Node));
    newNode->value=val;
    newNode->nextPtr=NULL;

    if(head==NULL){//case 1
        head=newNode;
    }else{
        newNode->nextPtr=head;
        head=newNode;
    }
}

void printLL(){
    struct Node * traveller;
    traveller = head;
    printf("\n***********************************\n");
    while(traveller!=NULL){
        printf("%d ",traveller->value);
        traveller=traveller->nextPtr;
    }
    printf("\n***********************************\n");
}

void insertTail(int val){
    struct Node * newNode =  malloc(sizeof(struct Node));
    newNode->value=val;
    newNode->nextPtr=NULL;

    if(head==NULL){
        head=newNode;
    }else{
        struct Node * traveller ;
        traveller=head;
        while(traveller->nextPtr!=NULL){
            traveller=traveller->nextPtr;
        }
        traveller->nextPtr=newNode;
    }
}

void insertMiddle(int val){
    struct Node* newNode =malloc(sizeof(struct Node));
    newNode->value=val;
    newNode->nextPtr=NULL;

    if(head==NULL){ // the ll is empty
        head=newNode;
        return;
    }

    if(head->nextPtr==NULL){ // the ll has only one element
        head->nextPtr=newNode;
        return;
    }

    int count = 0;

    struct Node * traveller = head;
    while(traveller!=NULL){
        count=count+1;
        traveller=traveller->nextPtr;
    }

    int middle = count/2;

    traveller=head;

    for(int i=1;i<middle;i++){
        traveller=traveller->nextPtr;
    }

    newNode->nextPtr=traveller->nextPtr;
    traveller->nextPtr=newNode;

}

void insertAfter(int currentValue, int newValue){
    if(head==NULL){
        printf("Cannot perform the insertAfter operation as the LL is empty\n");
        return;
    }

    struct Node *traveller = head;

    while(traveller!=NULL){
        if(traveller->value==currentValue){
            break;
        }else{
            traveller=traveller->nextPtr;
        }
    }

    if(traveller!=NULL){ // traveller managed to find the node with the currentValue
        struct Node* newNode =malloc(sizeof(struct Node));
        newNode->value=newValue;
        newNode->nextPtr=NULL;

        newNode->nextPtr=traveller->nextPtr;
        traveller->nextPtr=newNode;

    }else{ // current value not found
        printf("Value not found!\n");
    }
}


void updateValueAt(int pos, int newValue){
    struct Node * traveller = NULL;
    traveller=head;

    if(traveller==NULL){
        printf("Linked list is empty!\n");
        return;
    }

    int counter=0;
    while(traveller!=NULL){
        counter++;
        if(counter==pos){
            break;
        }else{
            traveller=traveller->nextPtr;
        }
    }

    if(traveller==NULL){
        printf("The position you mentioned does not exist!");
    }else{
        traveller->value=newValue;
    }
}


void deleteByValue(int val){
    if(head==NULL){
        printf("LL empty, nothing to delete!\n");
        return;
    }

    struct Node * traveller;
    struct Node * follower;

    traveller=head;
    follower=NULL;

    while(traveller!=NULL){
        if(traveller->value==val){
            break;
        }else{
            follower=traveller;
            traveller=traveller->nextPtr;
        }
    }

    if(traveller==NULL){
        printf("Value not found!\n");
    }else{
        if(follower!=NULL){
            follower->nextPtr=traveller->nextPtr;
            free(traveller);
        }else{
            // the follower is null
            // that means the traveller is on the very first node (head node)
            head=head->nextPtr;
            free(traveller);
        }
    }

}


int main(){
    insertHead(10);
    insertHead(20);
    insertHead(30);
    insertHead(40);
    insertHead(50);

    printLL();

    insertTail(100);
    insertTail(200);
    insertTail(300);

    printLL();

    printf("Inserting a node in the middle with value 1000\n");
    insertMiddle(1000);
    printLL();

    printf("Inserting a node in the middle with value 2000\n");
    insertMiddle(2000);
    printLL();
    printf("Inserting a node in the middle with value 3000\n");
    insertMiddle(3000);
    printLL();
    insertAfter(100,9999);
    printLL();
    insertAfter(88,9999);
    printLL();
    updateValueAt(10,-1);
    printLL();

    deleteByValue(2000);
    printLL();
    deleteByValue(40);
    deleteByValue(30);
    deleteByValue(20);
    printLL();
    deleteByValue(50);
    printLL();
    deleteByValue(10);
    deleteByValue(100);
    deleteByValue(-1);
    printLL();
    deleteByValue(3000);
    deleteByValue(1000);
    deleteByValue(200);
    printLL();
    deleteByValue(300);

    printLL();

    deleteByValue(100);
    printLL();
    return 0;
}