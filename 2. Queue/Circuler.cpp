#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int fornt;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size=n;
        arr=new int[size];
        fornt=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((fornt == 0 && rear == size-1) || (rear == (fornt-1)%(size-1) ))
        {
            //cout<<"Queue is Full";
            return false;
        }
        else if(fornt==-1){
            fornt=rear=0;

        }
        else if(rear==size-1 && fornt!=0)
        {
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
        
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(fornt==-1)
        {
            return -1;
        }
        int ans=arr[fornt];
        arr[fornt]=-1;
        if(fornt==rear){
            fornt=rear=-1;
        }
        else if(fornt==size-1)
        {
            fornt=0;
        }
        else{
            fornt++;
        }
        return ans;
    }
};
