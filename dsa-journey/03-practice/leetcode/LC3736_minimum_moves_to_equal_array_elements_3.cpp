class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=(int)nums.size();
        int maci=INT_MIN;
        int total=0;
        for(int i=0;i<n;i++){
            maci=max(maci,nums[i]);
            total+=nums[i];
        }
        return (n*maci)-total;
    }
};
