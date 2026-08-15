class ArrayQueue {
private:
    vector<int> A;
    int front;
    int rear;
public:
    ArrayQueue() {
        front=-1;
        rear=-1;
    }
    
    void push(int x) {
        A.push_back(x);
        rear++;
    }
    
    int pop() {
        int x=A[front+1];
        front++;
        return x;
    }
    
    int peek() {
        return A[front+1];
    }
    
    bool isEmpty() {
        return front==rear;
    }
};
