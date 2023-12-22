#include<bits/stdc++.h>

using namespace std;
//struct Node => does not provide OOPS features
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

int main(){
    vector<int> arr={2,5,7,8};

    Node*y =new Node(arr[0],nullptr);
    cout<<y<<endl;// print address

    cout<<y->data<<endl;

    cout<<y->next<<endl;

    //cout<<y.data<<endl; error like this 
    //if use Nodey =Node(arr[0],nullptr) =. just an object

    Node x= Node(arr[1],nullptr);//object 
    cout<<x.data;
}