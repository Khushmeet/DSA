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

void print(Node *head)
{
    cout << "List is: " << endl;
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void recursive_print(Node *head)
{
    if(head == NULL)
        return;
    cout << head->data << " ";
    recursive_print(head->next);
}

void recursive_print_reverse(Node *head)
{
    if(head == NULL)
        return;
    recursive_print_reverse(head->next);
    cout << head->data << " ";
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
    recursive_print(head);
    cout << endl;
    recursive_print_reverse(head);
}