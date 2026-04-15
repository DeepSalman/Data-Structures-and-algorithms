#include<stdio.h>
struct Node{
    int value;
    struct Node * next;
    struct Node * prev;
};

struct Node * head = NULL;

void insertTail(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head==NULL){
        head=newNode;
    }else{
        struct Node * traveller;
        traveller = head;

        while(traveller->next!=NULL){
            traveller=traveller->next;
        }

        traveller->next=newNode;
        //newNode->prev=traveller;
        traveller->next->prev=traveller;

    }
}

struct Node* search(int searcValue){
    struct Node * traveller;
    traveller=head;
    while(traveller!=NULL){
        if(traveller->value==searcValue){
                return traveller;
        }
        traveller=traveller->next;
    }
    return NULL;
}

void printDLL(){
    printf("\n***************************\n");
    struct Node * traveller = head;
    while(traveller!=NULL){
        printf("%d ",traveller->value);
        traveller=traveller->next;
    }
    printf("\n***************************\n");
}

void insertMiddle(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head==NULL){
        head=newNode;
        return;
    }

    if(head->next==NULL){
        head->next=newNode;
        newNode->prev=head;
        return;
    }

    struct Node *fast = head;
    struct Node *slow = head;

    while(1){
        if(fast->next==NULL){

            break;
        }
        if(fast->next->next==NULL){
            break;
        }
        fast = fast->next->next;
        slow = slow ->next;
        printf("In loop");
    }
//    printf("DEBUG");
//    printf("slow value = %d \n",slow->value);
//    printf("fast value = %d \n",fast->value);
    newNode->prev=slow;
    newNode->next=slow->next;
    slow->next=newNode;
    newNode->next->prev=newNode;
}

void updateValue(int currentValue, int newValue){
    struct Node *ptr = search(currentValue);

    if(ptr==NULL){
        printf("The value you want to change does not exist");
        return;
    }

    ptr->value=newValue;

}

void deleteValue(int value){
    struct Node *ptr = search(value);
    if(ptr==NULL){
        printf("The value you want to delete does not exist!\n");
        return;
    }

    if(ptr->next==NULL && ptr->prev==NULL){
        head=NULL;
        free(ptr);
        return ;
    }
    if(ptr->prev==NULL && ptr->next!=NULL){
        head=head->next;
        head->prev=NULL;
        free(ptr);
        return ;
    }
    if(ptr->prev!=NULL && ptr->next!=NULL){
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return ;

    }

    if(ptr->prev!=NULL && ptr->next==NULL){
        ptr->prev->next = NULL;
        free(ptr);
        return ;
    }




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