class Solution {
public:
    int f(int i,int j,vector<vector<int>>& memo,string& word1,string& word2){
        if(i<0&&j<0) return 0;
        if(i<0&&j>-1) return j+1;
        if(i>-1&&j<0) return i+1; 
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i]==word2[j]) memo[i][j]=f(i-1,j-1,memo,word1,word2);
        else{
            int del=f(i-1,j,memo,word1,word2);
            int rep=f(i-1,j-1,memo,word1,word2);
            int ins=f(i,j-1,memo,word1,word2);
            memo[i][j]=1+min(del,min(rep,ins));
        }
        return memo[i][j];
    }
    int minDistance(string word1, string word2) {
        int i=(int)word1.size();
        int j=(int)word2.size();
        vector<vector<int>> memo(i,vector<int>(j,-1));
        return f(i-1,j-1,memo,word1,word2);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=(int)word1.size();
        int n=(int)word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word2[j-1]==word1[i-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};
