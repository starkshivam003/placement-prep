class Solution {
public:
    int f(int i,int hold,vector<int>& prices,vector<vector<int>>& memo){
        if(i>=(int)prices.size()) return 0;
        if(memo[i][hold]!=-1) return memo[i][hold];
        int best;
        if(!hold){
            int buy=-prices[i]+f(i+1,1,prices,memo);
            int rest=f(i+1,0,prices,memo);
            best=max(buy,rest);
        }
        else{
            int sell=prices[i]+f(i+2,0,prices,memo);
            int rest=f(i+1,1,prices,memo);
            best=max(sell,rest);
        }
        return memo[i][hold]=best;
    }
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return f(0,0,prices,memo);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][1]=max(prices[i]+dp[i+2][0],dp[i+1][1]);
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        int a=0,b=0,c=0;
        for(int i=n-1;i>=0;i--){
            int x=max(-prices[i]+b,a);
            int y=max(prices[i]+c,b);
            c=a;
            a=x;
            b=y;
        }
        return a;
    }
};
