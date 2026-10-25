class Solution {
public:
    unsigned f(const string& s,const string& t,int i,int j,vector<vector<unsigned>>& memo,vector<vector<bool>>& done){
        if(j==(int)t.size()) return 1;
        if(i==(int)s.size()) return 0;
        if(done[i][j]) return memo[i][j];
        unsigned ways=f(s,t,i+1,j,memo,done);
        if(s[i]==t[j]){
            ways+=f(s,t,i+1,j+1,memo,done);
        }
        done[i][j]=true;
        return memo[i][j]=ways;
    }
    int numDistinct(string s, string t) {
        int m=(int)s.size();
        int n=(int)t.size();
        vector<vector<unsigned>> memo(m+1,vector<unsigned>(n+1,0));
        vector<vector<bool>> done(m+1,vector<bool>(n+1,false));
        return (int)f(s,t,0,0,memo,done);
    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        int m=(int)s.size();
        int n=(int)t.size();
        vector<vector<unsigned>> dp(m+1,vector<unsigned>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][n]=1;
        }
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                dp[i][j]=dp[i+1][j];
                if(s[i]==t[j]) dp[i][j]+=dp[i+1][j+1];
            }
        }
        return (int)dp[0][0];
    }
};
