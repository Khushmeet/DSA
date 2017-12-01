#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert_at_beginning(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = *head;
    if (*head != NULL)
        temp->next = *head;
    *head = temp;
}

struct Node* reverse(Node *head)
{
    stack<struct Node *> s;
    Node *temp = head;
    while(temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
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

int main()
{
    Node *head = new Node();
    insert_at_beginning(&head, 2);
    print(head);
    insert_at_beginning(&head, 3);
    print(head);
    insert_at_beginning(&head, 4);
    print(head);
    insert_at_beginning(&head, 5);
    print(head);
    head = reverse(head);
    print(head);
}