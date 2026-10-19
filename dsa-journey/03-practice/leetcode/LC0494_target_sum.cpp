class Solution {
public:
    int f(int i,int p,vector<int>& nums,vector<vector<int>>& memo){
        //if(p==0) return 1;
        if(i==(int)nums.size()&&p==0) return 1;
        if(i>=(int)nums.size()) return 0;
        if(memo[i][p]!=-1) return memo[i][p];
        int take=0;
        if(nums[i]<=p) take=f(i+1,p-nums[i],nums,memo);
        int skip=f(i+1,p,nums,memo);
        memo[i][p]=take+skip;
        return memo[i][p];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int num:nums) total+=num;
        int p=total+target;
        if(p%2) return 0;
        if(abs(target)>total) return 0; 
        p=p/2;
        int n=(int)nums.size();
        vector<vector<int>> memo(n,vector<int>(p+1,-1));
        return f(0,p,nums,memo);
    }
};

int findTargetSumWays(vector<int>& nums, int target) {
    int total = 0;
    for (int x : nums) total += x;
    if (abs(target) > total || (total + target) % 2) return 0;
    int P = (total + target) / 2, n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(P + 1, 0));
    dp[n][0] = 1;                                     

    for (int i = n - 1; i >= 0; i--) {
        for (int s = 0; s <= P; s++) {                
            dp[i][s] = dp[i + 1][s];                                  
            if (nums[i] <= s) dp[i][s] += dp[i + 1][s - nums[i]];     
        }
    }
    return dp[0][P];
}


int findTargetSumWays(vector<int>& nums, int target) {
    int total = 0;
    for (int x : nums) total += x;
    if (abs(target) > total || (total + target) % 2) return 0;
    int P = (total + target) / 2;

    vector<int> dp(P + 1, 0);
    dp[0] = 1;                                
    for (int x : nums)
        for (int s = P; s >= x; s--)          
            dp[s] += dp[s - x];
    return dp[P];
}
