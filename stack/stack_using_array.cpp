#include<iostream>

using namespace std;

int stack[10];
int top = -1;

void push(int x)
{
    if(top == 9) {
        cout << "Stack overflow" << endl;
        return;
    }
    top++;
    stack[top] = x;
}

void pop()
{
    if(top == -1) {
        cout << "Stack underflow" << endl;
        return;
    }
    top--;
}

int get_top_elm()
{
    return stack[top];
}

bool is_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void print()
{
    cout << "Stack is: ";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(1);
    print();
    push(4);
    print();
    push(0);
    print();
    push(7);
    print();
    pop();
    print();
}