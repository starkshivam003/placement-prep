class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    int l;
    KthLargest(int k, vector<int>& nums) : pq(nums.begin(),nums.end()),l(k) {
        while((int)pq.size()>l) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if((int)pq.size()>l) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
