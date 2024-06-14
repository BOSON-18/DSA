#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int val;

    Node(int data,Node* add){
        val=data;
        next=add;

    }

    Node(int data){
        val=data;
        next=NULL;
    }
};

void printLL(Node* head){
    Node* temp=head;

    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseLLI(Node* head){

    if(!head || !head->next) return head;

    Node* curr=head;
    Node* prev=NULL;

    while(curr){
        Node* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;

    }

    return prev;
}

Node* reverseLLR(Node* head){
    if(!head || !head->next) return head;

    Node* newHead=reverseLLR(head->next);

    Node* front=head->next;
    front->next=head;
    head->next=NULL;

    return newHead;
}


int main(){

    Node *head= new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    cout<<"Original List: ";
    printLL(head);

    cout<<"Reversed List Iterative: ";
   Node* newHead1= reverseLLI(head);
   printLL(newHead1);

   cout<<"Reverseing Reversed LL by recursion: ";
   Node* newHead2=reverseLLR(newHead1);
   printLL(newHead2);

    return 0;
}