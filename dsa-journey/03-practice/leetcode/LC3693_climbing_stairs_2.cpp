class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,INT_MAX/2);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            int x=costs[i-1];
            for(int j=max(0,i-3);j<i;j++){
                dp[i]=min(dp[i],(dp[j]+x+(i-j)*(i-j)));
            }
        }
        return dp[n];
    }
};
