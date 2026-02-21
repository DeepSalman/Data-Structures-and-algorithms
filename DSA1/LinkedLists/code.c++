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
    void push_back(int data){
        Node* newNode = new Node(data); //Creating a new node
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }
    void printli(){
        Node* temp=head;
        while(temp!=NULL){

            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main(){
    List li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_back(0);

    li.printli();


    return 0;
}