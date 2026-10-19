class Solution {
public:
    int f(int i,int p,vector<int>& nums,vector<vector<int>>& memo){
        if(i==(int)nums.size()) return 0;
        if(memo[i][p+1]!=-1) return memo[i][p+1];
        int take=0;
        if(p==-1||nums[i]>nums[p]) take=1+f(i+1,i,nums,memo);
        int skip=f(i+1,p,nums,memo);
        memo[i][p+1]=max(take,skip);
        return memo[i][p+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=(int)nums.size();
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
        return f(0,-1,nums,memo);
    }
};

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));   // row n = 0 (base case)

    for (int i = n - 1; i >= 0; i--) {
        for (int p = i - 1; p >= -1; p--) {
            int skip = dp[i + 1][p + 1];
            int take = 0;
            if (p == -1 || nums[i] > nums[p])
                take = 1 + dp[i + 1][i + 1];                 // nums[i] becomes last
            dp[i][p + 1] = max(take, skip);
        }
    }
    return dp[0][0];                                          // f(0, -1)
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0), cur(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int p = i - 1; p >= -1; p--) {
            int skip = next[p + 1];
            int take = (p == -1 || nums[i] > nums[p]) ? 1 + next[i + 1] : 0;
            cur[p + 1] = max(take, skip);
        }
        next = cur;
    }
    return next[0];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), ans = 1;
    vector<int> dp(n, 1);                         // dp[i] = LIS ending at i
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
    for (int x : dp) ans = max(ans, x);
    return ans;
}
