#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArrToLl(vector<int> & arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;

    for(int i=1;i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}

int length(Node* head){
    int count=0;
    Node*temp= head; 

      while(temp!=nullptr){
        //cout<<temp->data<<" ";
        temp=temp->next;
        count++;
       
    }

    return count;
    
}

int checkIfPresent(Node* head, int val){

    Node*temp = head;
      while(temp!=nullptr){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
      //  cout<<temp->data<<" ";
       
    }
   return 0;
    
}


int main(){
    vector<int> arr={69,5,8,7};
    Node* head=convertArrToLl(arr);
    Node*temp=head;
    
    // cout<<head->data<<endl;
    // cout<<head->next->data<<endl;ṇ
    cout<<"Print LL"<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
       
    }
    cout<<endl;

    int count=length( head);

    cout<<count<<endl;

    cout<<checkIfPresent(head,69);
    
}