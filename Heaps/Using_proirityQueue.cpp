#include <bits/stdc++.h>
using namespace std;
int main()
{

    cout << "priority Queue here :" << endl;

    // max Heap
    priority_queue<int> hp;
    hp.push(4);
    hp.push(2);
    hp.push(3);
    hp.push(5);
    hp.push(7);
    cout << " Top: " << hp.top() << endl;
    hp.pop();
    cout << " Top: " << hp.top() << endl;
    cout << "size: " << hp.size() << endl;

    return 0;
}