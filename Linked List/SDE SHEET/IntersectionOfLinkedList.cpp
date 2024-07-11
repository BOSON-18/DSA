#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

Node* IntersectionBrute(Node* head1,Node* head2){
       unordered_map<Node*,int> mpp;
        Node* temp1=head1;
        Node* temp2=head2;

        while(temp1){
            mpp[temp1]++;
            temp1=temp1->next;
        }

    while(temp2){
        if(mpp[temp2]) return  temp2;
        else {
            mpp[temp2]++;
            temp2=temp2->next;
        }

    }        
        return NULL;
    }
