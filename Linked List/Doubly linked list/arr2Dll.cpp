#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data=data1;
        next=NULL;
        prev=NULL;
    }

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

Node* convert2Dll(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],NULL,prev);
        prev->next=temp;
        prev=temp;
    }

    return head;

}

void print(Node* head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){

    vector<int> arr={1,3,8,7};
    Node* head=convert2Dll(arr);
    print(head);

    return 0;

}