#include<iostream>
#include<stack>

/*
    Efficient method for string reverse 
    take i and j as head and tail of array
    swap(i,j) and increment i and decrement j
    if i==j stop
*/

using namespace std;

void reverse(char *c, int len)
{
    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        s.push(c[i]);
    }

    for (int i = 0; i < len; i++)
    {
        c[i] = s.top();
        s.pop();
    }
}

int main()
{
    char c[6] = "Hello";
    cout << c << endl;
    reverse(c, strlen(c));
    cout << c;
}