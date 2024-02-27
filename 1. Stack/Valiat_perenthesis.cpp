#include <bits/stdc++.h>
using namespace std;
// namespace std;

bool isValidParenthesis(string s)
{
    stack<char> stk;

    for (int i = 0; i < s.length(); i++)
    {
        // cha er modde string gula rakhtesi;
        char ch = s[i];

        // opening bracket, push it;

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        // closing bracket, compare & pop.
        else
        {
            if (!stk.empty())
            {
                // opening bracket gula top rakhtesi tar pore closing bracket er sthe comparig kore pop kortesi;
                char top = stk.top();
                if (ch == '}' && top == '{' ||
                    ch == ')' && top == '(' ||
                    ch == ']' && top == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    // sob korar pore jodi stack empty hoy tahole balance na hole Not Balance
    if (stk.empty())
    {
        return true;
    }
    else
    {
        return true;
    }
}
int main()
{

    return 0;
}