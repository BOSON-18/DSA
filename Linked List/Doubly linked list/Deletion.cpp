#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1) {
        data = data1;
        next = NULL;
        prev = NULL;
    }

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convert2Dll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* back = head;

    head = head->next;
    head->prev = NULL;
    back->next = NULL;

    delete back;
    return head;
}

Node* deleteTail(Node* head){
    Node* temp=head;

    if(head==NULL||head->next==NULL){
        return NULL;
    }

    while(temp->next){
        temp=temp->next;
    }
    Node* newTail=temp->prev;
    newTail->next=NULL;
    temp->prev=NULL;
    delete(temp);

    return head;
}

Node* removeKElement(Node* head,int k){

    if(head == NULL){
        return NULL;
    }

    int count=0;

    Node* KNode=head;
    while(KNode !=NULL){
        count++;
        if(count == k) break;
        KNode=KNode->next;
    }

    Node* back=KNode->prev;
    Node* front= KNode->next;

    if(back ==NULL && front==NULL){
        return NULL;
        
    }
    else if(back==NULL){
        return deleteHead(head);

    }
    else if(front==NULL){
        deleteTail(head);    }

        back->next=front;
        front->prev=back;

        KNode->next=NULL;
        KNode->prev=NULL;

        delete KNode;

        return head;

}

void deleteNode(Node* temp){

    Node* back=temp->prev;
    Node* front=temp->next;

    if(front==NULL){
        back->next=NULL;
        temp->prev=NULL;
        free(temp);
        return ;
    }
    back->next=front;
    front->prev=back;

    temp->next=temp->prev=NULL;
    free(temp);

}

int main() {
    vector<int> arr = {1, 3, 8, 7};
    Node* head = convert2Dll(arr);
    cout << "Original List: ";
    print(head);
    cout << endl;

    //head = deleteHead(head);

    //cout << "List after deleting head: ";
    //print(head);
    //cout << endl;

    // head=deleteTail(head);

    //head=removeKElement(head,2);

    deleteNode(head->next);
    print(head);

    return 0;
}
