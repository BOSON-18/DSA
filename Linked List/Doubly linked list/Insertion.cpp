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

