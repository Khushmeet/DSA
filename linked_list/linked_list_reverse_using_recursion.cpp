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

// TODO: Bug fix needed
Node* reverse_list(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    reverse_list(head->next);
    Node *p = head->next;
    p->next = head;
    head->next = NULL;
    return head;
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

int main()
{
    Node *head = new Node();
    insert_at_n(&head, 2, 1);
    print(head);
    insert_at_n(&head, 3, 2);
    print(head);
    insert_at_n(&head, 4, 3);
    print(head);
    insert_at_n(&head, 7, 4);
    print(head);
    insert_at_n(&head, 14, 5);
    print(head);
    head = reverse_list(head);
    print(head);
}