#include<stdio.h>
struct Node{
    int value;
    struct Node* nextNode;
    struct Node* previousNode;

};

struct Node * head=NULL;

void insertHead(int value){
    struct Node* newNode= malloc(sizeof(struct Node));
    newNode->value=value;
    newNode->nextNode=NULL;
    newNode->previousNode=NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->nextNode=head;
        head->previousNode=newNode;
        head=newNode;
    }

}
void insertTail(int value){
    struct Node* newNode= malloc(sizeof(struct Node));
    newNode->value=value;
    newNode->nextNode=NULL;
    newNode->previousNode=NULL;


    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node * traveller=head;
    while(traveller->nextNode!=NULL){
        traveller=traveller->nextNode;
    }

    traveller->nextNode=newNode;
    newNode->previousNode=traveller;



}




void printDLL(){
    printf("\n***************************\n");
    struct Node * traveller = head;
    while(traveller!=NULL){
        printf("%d ",traveller->value);
        traveller=traveller->nextNode;
    }
    printf("\n***************************\n");
}


int main(){
    printDLL();
    insertMiddle(100);
    printDLL();
    insertMiddle(200);
    printDLL();
    insertMiddle(300);
    printDLL();
    insertMiddle(400);
    printDLL();
    insertMiddle(500);
    printDLL();
    insertMiddle(600);
    printDLL();

    insertMiddle(600);
    printDLL();

    struct Node *ptr;
    ptr = search(300);

    if(ptr==NULL){
        printf("value not found!");
    }else{
        printf("value has been found!");
        ptr->value=30000;
        printDLL();
    }
    updateValue(400,4000);
    printDLL();
    updateValue(-50,4000);
    printDLL();

    deleteValue(4000);
    deleteValue(30000);
    printDLL();

    deleteValue(500);
    deleteValue(600);
    printDLL();

    deleteValue(100);
    deleteValue(200);
    printDLL();
    deleteValue(600);
    printDLL();
    deleteValue(600);
    printDLL();
    return 0;
}