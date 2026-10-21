class Solution {
public:
    int f(int l,int r,vector<vector<int>>& memo,vector<int>& padded){
        if(r==l+1) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int best=INT_MIN;
        for(int i=l+1;i<r;i++){
            int left=f(l,i,memo,padded);
            int right=f(i,r,memo,padded);
            int prod=padded[l]*padded[i]*padded[r];
            best=max(best,left+right+prod);
        }
        return memo[l][r]=(best==INT_MIN?0:best);
    }
    int maxCoins(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> padded(n+2,1);
        for(int i=0;i<n;i++){
            padded[i+1]=nums[i];
        }
        vector<vector<int>> memo(n+2,vector<int>(n+2,-1));
        return f(0,n+1,memo,padded);
    }
};


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> a(n + 2, 1);                        
        for (int i = 0; i < n; i++) a[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));   

        for (int len = 2; len <= n + 1; len++) {        
            for (int l = 0; l + len <= n + 1; l++) {
                int r = l + len;
                for (int k = l + 1; k < r; k++) {       
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
