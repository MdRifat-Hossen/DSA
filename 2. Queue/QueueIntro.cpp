#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation queue
    queue<int> q;
    q.push(9);

    q.push(90);

    q.push(93);

    cout << "Queue size is " << q.size() << endl;

    q.pop();
    cout << "Queue size is " << q.size() << endl;
    q.pop();

    cout << "Queue size is " << q.size() << endl;

    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    cout << "Queue is front " << q.front() << endl;

    return 0;
}