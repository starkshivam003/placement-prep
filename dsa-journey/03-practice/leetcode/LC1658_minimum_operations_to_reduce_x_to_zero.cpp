class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum=0;
        for(int num:nums) totalsum+=num;
        int target=totalsum-x;
        if(target<0) return -1;
        if(target==0) return (int)nums.size();
        int n=(int)nums.size();
        int l=0,sum=0,maxlen=-1;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>target&&l<=r){
                sum-=nums[l];
                l++;
            }
            if(sum==target){
                maxlen=max(maxlen,r-l+1);
            }
        }
        return maxlen==-1?-1:n-maxlen;
    }
};
