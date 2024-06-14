#include <iostream>
#include <vector>
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

Node *mergeLL(Node *head1, Node *head2)
{
    vector<int> NodeVals;

    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            NodeVals.push_back(head1->val);
            head1 = head1->next;
        }
        else
        {
            NodeVals.push_back(head2->val);
            head2 = head2->next;
        }
    }

    while (head1)
    {
        NodeVals.push_back(head1->val);
        head1 = head1->next;
    }

    while (head2)
    {
        NodeVals.push_back(head2->val);
        head2 = head2->next;
    }

    Node *newHead = new Node(NodeVals[0]);
    Node *temp = newHead;
    for (int i = 1; i < NodeVals.size(); i++)
    {
        temp->next = new Node(NodeVals[i]);
        temp = temp->next;
    }

    return newHead;
}

Node *optimalMerging(Node *head1, Node *head2)
{

    if (!head1 && !head2)
        return NULL;

    Node *firstNode;
    if (head1->val <= head2->val)
    {
        firstNode = head1;
        head1 = head1->next;
    }
    else
    {
        firstNode = head2;
        head2 = head2->next;
    }

    Node *newhead = new Node(firstNode->val);
    Node *temp = newhead;

    while (head1 && head2)
    {

        if (head1->val <= head2->val)
        {
            temp->next = new Node(head1->val);
            head1 = head1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = new Node(head2->val);
            head2 = head2->next;
            temp = temp->next;
        }
    }

    while (head1)
    {
        temp->next = new Node(head1->val);
        head1 = head1->next;
        temp = temp->next;
    }

     while (head2)
    {
        temp->next = new Node(head2->val);
        head2 = head2->next;
        temp = temp->next;
    }

    return newhead;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        /* code */
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}
int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next=new Node(3);
    head->next->next->next = new Node(4);

    cout << "Printing LL1: ";
    printLL(head);

    Node *head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    head2->next->next->next=new Node(69);
    cout << "Printing LL2: ";
    printLL(head2);

    // Node *newHead = mergeLL(head, head2);
    Node* newHead=optimalMerging(head,head2);
    cout << "Printing merged: ";
    printLL(newHead);
    return 0;
}