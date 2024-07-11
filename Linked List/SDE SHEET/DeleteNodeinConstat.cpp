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

void removeNode(Node* node){
    node->val=node->next->val;

    if(node->next->next){
        node->next=node->next->next;
    }else{
        node->next=NULL;
    }
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

    temp = head;

    for (int i = 1; i < 1; i++)
    {
        temp = temp->next;
    }

    cout << "Node to be removed:\t" << temp->val << endl;

    cout << "Printing Original LL: ";
    printLL(head);

    cout<<"After Removing Node:";
    removeNode(temp);
    printLL(head);

    return 0;
}