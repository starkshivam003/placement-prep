class Solution {
public:
    int f(vector<int>& nums,int i){
        if(i>=(int)nums.size()) return 0;
        return max(nums[i]+f(nums,i+2),f(nums,i+1));
    }
    int rob(vector<int>& nums) {
        return f(nums,0);
    }
};

class Solution {
public:
    int f(vector<int>& nums,int i,vector<int>& memo){
        if(i>=(int)nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i]=max(nums[i]+f(nums,i+2,memo),f(nums,i+1,memo));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        vector<int> memo((int)nums.size(),-1);
        return f(nums,0,memo);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> ans(n+2,0);
        for(int i=n-1;i>=0;i--){
            ans[i]=max(nums[i]+ans[i+2],ans[i+1]);
        }
        return ans[0];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        int a=0,b=0;
        for(int i=n-1;i>=0;i--){
            int c=max(nums[i]+b,a);
            b=a;
            a=c;
        }
        return a;
    }
};
