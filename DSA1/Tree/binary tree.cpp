#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    struct TreeNode * parent;
    struct TreeNode * left;
    struct TreeNode * right;
};


TreeNode * root = NULL;

void insertTree(int val){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value=val;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->parent=NULL;
    if(root==NULL){
        root = newNode;
        return;
    }
    TreeNode * traveller = root;
    TreeNode * follower = NULL;
    while(traveller!=NULL){
        if(newNode->value  >=  traveller->value){
            follower=traveller;
            traveller=traveller->right;
        }else{
            follower=traveller;
            traveller=traveller->left;
        }
    }
    if(newNode->value  >=  follower->value){
        follower->right=newNode;
        newNode->parent=follower;
    }else{
        follower->left=newNode;
        newNode->parent=follower;
    }




}

void preOrder(TreeNode * node){
    if(node==NULL){
        return;
    }

    cout<<node->value<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

// implement post order and inorder similarly


int sum=0;
void findSum(TreeNode * node){
    if(node==NULL){
        return;
    }

    sum=sum+node->value;
    findSum(node->left);
    findSum(node->right);
}

// similarly try sumOfLeaves, sumOfInternalNodes


TreeNode* searchTree(int svalue){
    TreeNode * traveller = root;

    while(traveller!=NULL){
        if(traveller->value == svalue){
            break;
        }else if(svalue> traveller->value){
            traveller=traveller->right;
        }else{
            traveller=traveller->left;
        }
    }

    return traveller;
}

int main(){
    //struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    TreeNode *newNode = (TreeNode*)malloc(sizeof(struct TreeNode));
//    newNode->value=10;
//    newNode->left=NULL;
//    newNode->right=NULL;
//    newNode->parent=NULL;
//

    insertTree(5);
    insertTree(10);
    insertTree(2);
    insertTree(-1);
    insertTree(4);
    insertTree(7);
    insertTree(15);


    preOrder(root);

    sum=0;
    findSum(root);

    cout<<"\nThe entire sum of the tree nodes is "<<sum<<endl;

    TreeNode * ptr =searchTree(4);

    if(ptr==NULL){
        cout<<"Node with the search value was not found!"<<endl;
    }else{
        cout<<"Value found!"<<endl;
        ptr->value=400;
        preOrder(root);
        // simiarly after making it 400, add a left child and right child to it using the pointer ptr
    }
    return 0;
}
