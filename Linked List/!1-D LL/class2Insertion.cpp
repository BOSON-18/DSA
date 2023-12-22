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



void printLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* insertHead(Node* head,int val){

    Node* temp= new Node(val,head);

    return temp;
}

Node* insertTail(Node* head,int val){

    Node*temp=new Node(val,NULL);

    if(head==NULL){
        return new Node(val,NULL);
    }

    Node* curr=head;
    while(curr->next){
        curr=curr->next;
    }
    curr->next=temp;

    return head;
}

Node* insertAtK(Node*head,int val,int k){
    Node* temp= head;
    int count=0;

    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
          cout<<"Fuck off"<<endl;
        }
    }

    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    while(temp){
        count++;
        if(count==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
           break;
        }
        temp=temp->next;
        if(count<k-1 && temp==NULL){
            cout<<"fuck off"<<endl;
        }
    }

    return head;
}


Node* insertBeforeValue(Node*head,int val,int k){
    Node* temp= head;
    

    if(head==NULL){
       return NULL;
    }

    if(head->data==k){
        return new Node(val,head);
    }

   
    while(temp->next!=NULL){
        
        if(temp->next->data==k){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
           break;
        }
        temp=temp->next;
       
    }

    return head;
}





int main(){
    vector<int> arr={69,5,8,7};
    Node* head=convertArrToLl(arr);
//     head=insertHead(head,10);
    
//     printLL(head);

//     head=insertTail(head,80);
// cout<<endl;
//     printLL(head);

//insertAtK(head,89,9);
head=insertBeforeValue(head,23,69);
printLL(head);
   
    
}