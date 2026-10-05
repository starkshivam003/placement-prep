class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        int sum=0,ans=0;
        seen[0]=1;
        for(int& num:nums){
            sum+=num;
            if(seen.count(sum-k)) ans+=seen[sum-k];
            seen[sum]++;
        }
        return ans;
    }
};
