class ArrayStack {
private:
    vector<int> A;
    int upper;
public:
    ArrayStack() {
        upper=-1;
    }
    
    void push(int x) {
        A.push_back(x);
        upper++;
    }
    
    int pop() {
        int x=A[upper];
        A.pop_back();
        upper--;
        return x;
    }
    
    int top() {
        return A[upper];
    }
    
    bool isEmpty() {
        return upper==-1;
    }
};
