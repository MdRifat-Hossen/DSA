#include <bits/stdc++.h>
using namespace std;
class queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    queue()
    {
        size = 10001;
        arr = new int[size];
    }
    void enque(int val)
    {
        if (qfront == rear)
        {
            cout << "Queue Is Full" << endl;
        }
        else
        {
            arr[rear] = val;
            rear++;
        }
    }

    int dequeue()
    {

        if (qfront == rear)
        {
            // cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    bool isempty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    queue.enque(30);

    return 0;
}