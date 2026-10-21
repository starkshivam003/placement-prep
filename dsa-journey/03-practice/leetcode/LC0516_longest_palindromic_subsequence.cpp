class Solution {
public:
    int f(int i,int j,const string& s,vector<vector<int>>& memo){
        if(i>j) return 0;
        if(i==j) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s[i]==s[j]) memo[i][j]=2+f(i+1,j-1,s,memo);
        else memo[i][j]=max(f(i+1,j,s,memo),f(i,j-1,s,memo));
        return memo[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=(int)s.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return f(0,n-1,s,memo);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=(int)s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
