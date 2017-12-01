#include <iostream>
#include <stack>

using namespace std;

bool check_balance_paren(string st)
{
    stack<char> s;
    for (auto i : st)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            s.push(i);
        }
        if (i == ')' || i == '}' || i == ']')
        {
            if (s.empty())
                return false;
            else
            {
                if (i == ')' && s.top() == '(')
                    s.pop();
                else if (i == '}' && s.top() == '{')
                    s.pop();
                else if (i == ']' && s.top() == '[')
                    s.pop();
                else
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    string exp = "[()()]";
    bool ans = check_balance_paren(exp);
    cout << ans;
}