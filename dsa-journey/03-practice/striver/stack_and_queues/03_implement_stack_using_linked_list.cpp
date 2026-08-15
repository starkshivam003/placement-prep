class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedListStack {
    ListNode *head;
public:
    LinkedListStack() {
        head=nullptr;
    }
    
    void push(int x) {
        head=new ListNode(x,head);
    }
    
    int pop() {
        int x=head->val;
        ListNode *temp=head;
        head=head->next;
        delete temp;
        return x;
    }
    
    int top() {
        return head->val;
    }
    
    bool isEmpty() {
        return head==nullptr;
    }
};
