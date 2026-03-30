#include<stdio.h>
#include<stdlib.h>


struct Node{
    int value;
    struct Node* nextNode;

};
struct Node *head=NULL;

void insertHead(int n){
    struct Node * newNode=malloc(sizeof(struct Node));
    newNode->value=n;
    newNode->nextNode=NULL;

    if(head==NULL){
        head = newNode;
    }
    else{
        newNode->nextNode=head;
        head=newNode;
    }


}

void insertTail(int n){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->value=n;
    newNode->nextNode=NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node * Traveller;
        Traveller=head;
        while(Traveller->nextNode!=NULL){
            Traveller=Traveller->nextNode;
        }
        Traveller->nextNode=newNode;
    }



}

void printLL(){
    struct Node * traveller;
    traveller=head;
    while(traveller!=NULL){
        printf("Your Traveller is at value: %d\n",traveller->value);
        traveller=traveller->nextNode;
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
    return 0;

}
