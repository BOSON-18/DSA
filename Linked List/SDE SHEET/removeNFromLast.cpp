#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int val;

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

Node *removeNFromLast(Node *head, int n)
{
    Node *temp = head;
    int count = 0;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    if (count == n)
    {
        return head->next;
    }

    temp = head;

    count -= n;

    while (temp)
    {
        count--;
        if (count == 0)
        {
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node* optimized(Node* head,int n){
    Node* slow=head;
    Node* fast=head;

    for(int i=0;i<n;i++){
        fast=fast->next;
    if(!fast){
        return head->next;
    }
    }


    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=slow->next->next;

    return head;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i < 6; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    cout << "Prinitng LL: ";
    printLL(head);


// Time Complexity :- O(N+N)=O(N)
    // cout << "LL After removing the given node: ";
    // Node *start = removeNFromLast(head, 4);
    // printLL(start);

    cout << "LL After removing the given node: ";
    Node *start = optimized(head, 8);
    printLL(start);
    return 0;
}