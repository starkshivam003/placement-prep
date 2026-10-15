class Solution {
public:
    int f(vector<int>& nums,int i,int end){
        if(i>end) return 0;
        return max(nums[i]+f(nums,i+2,end),f(nums,i+1,end));
    }
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==1) return nums[0];
        return max(f(nums,0,n-2),f(nums,1,n-1));
    }
};

class Solution {
public:
    int f(vector<int>& nums,int i,int end,vector<int>& memo){
        if(i>end) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i]=max(nums[i]+f(nums,i+2,end,memo),f(nums,i+1,end,memo));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==1) return nums[0];
        vector<int> memo1(n,-1);
        vector<int> memo2(n,-1);
        return max(f(nums,0,n-2,memo1),f(nums,1,n-1,memo2));
    }
};

class Solution {
public:
    int f(vector<int>& nums,int start,int end){
        int a=0,b=0;
        for(int i=end;i>=start;i--){
            int c=max(nums[i]+b,a);
            b=a;
            a=c;
        }
        return a;
    }
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==1) return nums[0];
        return max(f(nums,0,n-2),f(nums,1,n-1));
    }
};
