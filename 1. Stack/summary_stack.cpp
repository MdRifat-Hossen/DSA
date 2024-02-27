#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack is OverFolow";
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is UderFlow" << endl;
        }
    }
    int peak()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.peak() << endl;
    s.pop();
    cout << s.peak() << endl;

    s.pop();
    cout << s.peak() << endl;
    s.pop();
    cout << s.peak() << endl;
    s.pop();
    cout << s.peak() << endl;

    return 0;
}