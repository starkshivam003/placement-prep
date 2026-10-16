class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone=0;
        int l=0;
        for(int r=0;r<(int)nums.size();r++){
            if(nums[r]==0) l=r+1;
            else maxone=max(maxone,(r-l+1));
        }
        return maxone;
    }
};
