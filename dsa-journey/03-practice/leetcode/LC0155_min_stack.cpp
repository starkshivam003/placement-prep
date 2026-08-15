class MinStack {
private:
    vector<int> A;
    vector<int> B;
    int upper;
    int bupper;
public:
    MinStack() {
        upper=-1;
        bupper=-1;
    }
    
    void push(int value) {
        A.push_back(value);
        upper++;
        int mini=B.empty()?value:min(B[bupper],value);
        B.push_back(mini);
        bupper++;
    }
    
    void pop() {
        A.pop_back();
        B.pop_back();
        upper--;
        bupper--;
    }
    
    int top() {
        return A[upper];
    }
    
    int getMin() {
        return B[bupper];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
