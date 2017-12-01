#include <iostream>
#include <stack>
#include <string>

using namespace std;

int eval(string st)
{
    stack<char> s;
    for (auto i : st)
    {
        if (i != '+' && i != '-' && i != '*')
        {
            s.push(i);
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            if (i == '+')
                s.push(op1 - '0' + op2 - '0');
            else if (i == '-')
                s.push(op1 - '0' - op2 - '0');
            else
                s.push(op1 - '0' * op2 - '0');
        }
    }
    return s.top();
}

int main()
{
    string expr = "23+";
    int ans = eval(expr);
    cout << ans;
}