#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next; // this next pointer will point to the next node in the linked list
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

};

class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int data){
        Node* newNode = new Node(data); // create a new node with the given data
        if(head==NULL){
            head=tail=newNode;
        } //If the list is empty the new node becomes both the head and tail of the list
        else{
            newNode->next=head; //point the new node's next to the current head of the list
            head=newNode; //update the head of the list to be the new node
        }
    }
    
};

int main(){
    List li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);



    return 0;
}