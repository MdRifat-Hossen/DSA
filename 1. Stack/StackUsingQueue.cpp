class MyQueue {
private:
    int size;
    ListNode* head;
    ListNode* end;

public:
    MyQueue() {
        this->size = 0;
        this->head = new ListNode(-1);
        this->end = new ListNode(0);
        this->head->next = this->end;
    }
    
    void push(int x) {
        if (size == 0) {
            if (head->next) {
                this->end->val = x;
                size++;
                return;
            } else {
                this->end = new ListNode(x);
                this->head->next = this->end;
                size++;
                return;
            }
        }
        ListNode* tmp = new ListNode(x);
        this->end->next = tmp;
        this->end = this->end->next;
        size++;
        return;
    }
    
    int pop() {
        int removed = head->next->val;
        head->next = head->next->next;
        size--;
        return removed;
    }
    
    int peek() {
        return head->next->val;
    }
    
    bool empty() {
        return size == 0;
    }
};
