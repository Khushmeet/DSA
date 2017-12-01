#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = (struct Node *)malloc(sizeof(struct Node));

struct Node* get_new_node(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert_at_0(int data)
{
    Node *temp = get_new_node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void print()
{
    Node *temp = head;
    cout << "List is ";
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse()
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "List is ";
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    insert_at_0(7);
    insert_at_0(0);
    insert_at_0(4);
    insert_at_0(1);
    print();
    print_reverse();
}