#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Love";
    stack<char> c;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        c.push(ch);
    }
    string ans = "";
    while (!c.empty())
    {
        char ch = c.top();
        ans.push_back(ch);
        c.pop();
    }
    cout << "Ans is :" << ans;
    return 0;
}