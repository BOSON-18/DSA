#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }

    Node(int data, Node *front)
    {
        val = data;
        next = front;
    }
};

void printLL(Node* head){
    Node *temp=head;

    while(temp){
        cout<<temp->val<<" " ;
        temp=temp->next;
    }

    cout<<endl;
}

Node* findMiddle(Node* head){
    Node* temp=head;

    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }

    int mid=count/2 +1;

temp=head;
    while(temp){
        mid--;
        if(mid==0) break;

        temp=temp->next;
    }

    return temp;
}

int TortoiseHarse(Node* head){

        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->val;
}

int main()
{
    Node *head = new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    Node* temp=head;

    for(int i=2;i<6;i++){
        temp->next=new Node(i);
        temp=temp->next;
    }
    cout<<"Printing LL: ";
    printLL(head);

    cout<<"Middle of LL is : "<<findMiddle(head)->val<<endl;

    cout<<"Midlle of LL by Tortoie Hare is: "<<TortoiseHarse(head)<<endl;


  



    return 0;
}