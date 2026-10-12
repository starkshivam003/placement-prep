class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=(int)nums.size();
        int sum=0,zero=0;
        for(int& num:nums){
            if(num==0) zero++;
            sum+=num;
        }
        if(zero==0) return 0;
        return (n*(n+1))/2-sum;
    }
};
