//attempt 1: time-O(n) space-O(n)
/*
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> max_A;
        vector<int> min_B;
        int n=(int)nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            max_A.emplace_back(maxi);
        }
        for(int i=n-1;i>-1;i--){
            if(nums[i]<mini){
                mini=nums[i];
            }
            min_B.emplace_back(mini);
        }
        reverse(min_B.begin(),min_B.end());
        for(int i=0;i<n;i++){
            max_A[i]-=min_B[i];
        }
        for(int i=0;i<n;i++){
            if(max_A[i]<=k){
                return i;
            }
        }
        return -1;
    }
};*/
//attempt 2: more optimised
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=(int)nums.size();
        int max_A[n];
        int min_B[n];

        int maxi=INT_MIN;
        for (int i=0;i<n;i++) {
            maxi=max(maxi,nums[i]);
            max_A[i]=maxi;
        }

        int mini=INT_MAX;
        for (int i=n-1; i>=0;i--) {
            mini=min(mini,nums[i]);
            min_B[i]=mini;
        }

        for (int i=0;i<n;i++) {
            if (max_A[i]-min_B[i]<=k) {
                return i;
            }
        }
        return -1;
    }
};
