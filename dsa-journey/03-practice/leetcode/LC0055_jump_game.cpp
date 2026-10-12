class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=(int)nums.size();
        int f=0;
        for(int i=0;i<n;i++){
            if(i>f) return 0;
            f=max(f,i+nums[i]);
            if(f>=n-1) return true;
        }
        return true;
    }
};
