class Solution {
public:
    int f(int a,int n,vector<int>& coins,vector<vector<int>>& memo){
        if(a==0) return 1;
        if(n>=(int)coins.size()) return 0;
        if(memo[n][a]!=-1) return memo[n][a];
        int take=0;
        if(coins[n]<=a) take=f(a-coins[n],n,coins,memo);
        int skip=f(a,n+1,coins,memo);
        return memo[n][a]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=(int)coins.size();
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        return f(amount,0,coins,memo);
    }
};
