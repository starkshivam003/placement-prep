//attempt 1: time-O(n^2) Naive Solution
/*
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=(int)nums.size();
        if(n==k){
            return *max_element(nums.begin(),nums.end());
        }
        for(int i=0;i<n;i++){
            mpp[nums[i]]=0;
        }
        for(int i=0;i<(n-k+1);i++){
            for(int j=i;j<(i+k);j++){
                mpp[nums[j]]++;
            }
        }
        int ans_max=INT_MIN;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]==1&&nums[i]>ans_max){
                ans_max=nums[i];
            }
        }
        if(ans_max==INT_MIN){
            return -1;
        }
        return ans_max;
    }
};
*/
//attempt 2: time-O(n) space-O(n)
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if(n == k){
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]].emplace_back(i);
        }

        int ans = -1;
        for(auto& [key, val] : mpp){
            if(val.size() != 1){
                continue;
            }
            int idx = val.front();
            int window = (min(idx, n - k)) - (max(idx - k + 1, 0)) + 1;
            if(window == 1){
                ans = max(ans, key);
            }
        }
        return ans;
    }
};
