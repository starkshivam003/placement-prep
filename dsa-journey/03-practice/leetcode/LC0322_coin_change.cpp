class Solution {
public:
    const int INF=1e9;
    int f(int a,vector<int>& coins,vector<int>& memo){
        if(!a) return 0;
        if(memo[a]!=-1) return memo[a];
        int best=INF;
        for(int c:coins){
            if(c<=a){
                int sub=f(a-c,coins,memo);
                if(sub!=INF) best=min(best,1+sub);
            }
        }
        memo[a]=best;
        return memo[a];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-1);
        int ans=f(amount,coins,memo);
        return ans==INF?-1:ans;
    }
};
