class Solution {
public:
    long long mod=1e9+7;
    long long f(int i,int j,vector<vector<vector<long long>>>& memo,const vector<vector<int>>& grid,int dir,const int& m,const int& n){
        if(i>=m||j>=n) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(memo[i][j][dir]!=-1) return memo[i][j][dir];
        long long count=0;
        if(grid[i][j]==1){
            if(dir==0){
                count=f(i+1,j,memo,grid,1,m,n)%mod;
            }
            else{
                count=f(i,j+1,memo,grid,0,m,n)%mod;
            }
        }
        else{
            count=((f(i,j+1,memo,grid,0,m,n)%mod)+(f(i+1,j,memo,grid,1,m,n)%mod))%mod;
        }
        return memo[i][j][dir]=count;
    }   
    int uniquePaths(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<vector<long long>>> memo(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return (int)f(0,0,memo,grid,0,m,n);
    }
};

class Solution {
public:
    long long mod=1e9+7; 
    int uniquePaths(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(2,0)));
        dp[m-1][n-1][0]=1;
        dp[m-1][n-1][1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1) continue;
                if(grid[i][j]==1){
                    dp[i][j][0]=dp[i+1][j][1];
                    dp[i][j][1]=dp[i][j+1][0];
                }
                else{
                    dp[i][j][0]=(dp[i+1][j][1]+dp[i][j+1][0])%mod;
                    dp[i][j][1]=(dp[i+1][j][1]+dp[i][j+1][0])%mod;
                }
            }
        }
        return (int)dp[0][0][0];
    }
};
