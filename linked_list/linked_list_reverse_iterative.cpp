#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert_at_n(Node **head, int data, int position)
{
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (position == 1)
    {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    Node *temp_head = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp_head = temp_head->next;
    }
    temp1->next = temp_head->next;
    temp_head->next = temp1;
}

void reverse(Node **head)
{
    Node *prev, *next, *current;
    current = *head;
    prev = NULL;
    while(current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
    insert_at_n(&head, 2, 1);
    print(head);
    insert_at_n(&head, 3, 2);
    print(head);
    insert_at_n(&head, 4, 3);
    print(head);
    insert_at_n(&head, 5, 4);
    print(head);
    insert_at_n(&head, 23, 5);
    print(head);
    reverse(&head);
    print(head);
}