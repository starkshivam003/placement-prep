/*
//attempt 1: brute force - time[O(n^2)] and space[O(n)]
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=(int)nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<((2*n)-1);j++){
                if(nums[j%n]>nums[i]){
                    ans.push_back(nums[j%n]);
                    break;
                }
            }
            if((int)ans.size()==i){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
*/
//attempt 2: similar to brute force but using stack
/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=(int)nums.size();
        stack<int> stk;
        for(int i=0;i<(int)nums.size();i++){
            if(!stk.empty()&&nums[stk.top()]<nums[i]){
                ans.push_back(nums[i]);
                stk.pop();
            }
            else if(!stk.empty()&&nums[stk.top()]>=nums[i]){
                int m=stk.top();
                int flag=0;
                for(int j=m+1;j<(2*n)-1;j++){
                    if(nums[j%n]>nums[m]){
                        ans.push_back(nums[j%n]);
                        stk.pop();
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans.push_back(-1);
                    stk.pop();
                }
            }
            stk.push(i);
        }
        int m=stk.top();
        stk.pop();
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[m]){
                ans.push_back(nums[i]);
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans.push_back(-1);
        }
        return ans;
    }
};
*/
// attempt 3: using monotonic stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 2*n - 1; i >= 0; i--){
            int idx = i % n;
            while(!st.empty() && nums[st.top()] <= nums[idx]) st.pop();
            if(i < n){
                ans[idx] = st.empty() ? -1 : nums[st.top()];
            }
            st.push(idx);
        }
        return ans;
    }
};
