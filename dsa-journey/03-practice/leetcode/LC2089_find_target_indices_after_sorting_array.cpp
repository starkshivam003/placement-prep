class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count_less=0;
        int count_equal=0;
        int n=(int)nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<target) count_less++;
            else if(nums[i]==target) count_equal++;
        }
        if(!count_equal) return {};
        vector<int> ans(count_equal);
        ans[0]=count_less;
        for(int i=1;i<count_equal;i++){
            ans[i]=1+ans[i-1];
        }
        return ans;
    }
};
