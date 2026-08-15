class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x): val(x),next(nullptr){};
    ListNode(int x, ListNode *next): val(x),next(next){};
};

class LinkedListQueue {
    ListNode *head,*tail;
public:
    LinkedListQueue() {
        head=nullptr;
        tail=nullptr;
    }
    
    void push(int x) {
        if(head==nullptr){
            head=new ListNode(x,head);
            tail=head;
        }
        else{
            tail->next=new ListNode(x,nullptr);
            tail=tail->next;
        }
    }
    
    int pop() {
        int x=head->val;
        ListNode *temp;
        temp=head;
        head=head->next;
        delete temp;
        return x;
    }
    
    int peek() {
        return head->val;
    }
    
    bool isEmpty() {
        return head==nullptr;
    }
};
