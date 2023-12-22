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

Node* removehead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;

    return head;
}

Node* removetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;

    return head;
}

void printLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removeK(Node* head,int k){
    if(head==NULL) return head;

    if(k==1){
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}

Node* removeElement(Node* head,int k){
    if(head==NULL) return head;

    if(head->data==k){
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }
   
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
       
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}




int main(){
    vector<int> arr={69,5,8,7};
    Node* head=convertArrToLl(arr);
    // cout<<head->data;
    // cout<<endl;
    // head=removehead(head);
    // cout<<head->data;
    // removetail(head);
    // printLL(head);

    //head=removeK(head,1);
    head=removeElement(head,5);
    printLL(head);
   
    
}