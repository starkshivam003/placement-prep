/*
class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>& ans){
        if(i>=(int)cost.size()) return 0;
        if(ans[i]!=-1) return ans[i];
        ans[i]=cost[i]+min(f(i+1,cost,ans),f(i+2,cost,ans));
        return ans[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ans((int)cost.size(),-1);
        return min(f(0,cost,ans),f(1,cost,ans));
    }
};
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=(int)cost.size();
        vector<int> ans(n+2,0);
        for(int i=n-1;i>-1;i--){
            ans[i]=cost[i]+min(ans[i+1],ans[i+2]);
        }
        return min(ans[0],ans[1]);
    }
};
