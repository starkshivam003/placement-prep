class Solution {
public:
    void f(int i,int a,bool& ans,vector<int>& nums,vector<vector<int>>& memo){
        if(!ans){
            if(a==0){
                ans=true;
                return;
            }
            if(i>=(int)nums.size()) return;
            if(memo[i][a]!=-1) return;
            if(nums[i]<=a) f(i+1,a-nums[i],ans,nums,memo);
            f(i+1,a,ans,nums,memo);
            memo[i][a]=0;
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=(int)nums.size();
        int total=0;
        for(int num:nums){
            total+=num;
        }
        if(total%2) return false;
        bool ans=false;
        vector<vector<int>> memo(n,vector<int>((total/2)+1,-1));
        f(0,total/2,ans,nums,memo);
        return ans;
    }
};

/*
bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int x : nums) total += x;
    if (total % 2) return false;
    int target = total / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums)
        for (int s = target; s >= x; s--)      // BACKWARD
            if (dp[s - x]) dp[s] = true;
    return dp[target];
}
*/
