#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void pop()
{
    Node *temp;
    if (head == NULL)
        return;
    temp = head;
    head = head->next;
    delete temp;
}

void print(Node *head)
{
    cout << "List is: " << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// TODO: Fix error
int main()
{
    push(1);
    print(head);
    push(4);
    print(head);
    push(7);
    print(head);
    pop();
    print(head);
}