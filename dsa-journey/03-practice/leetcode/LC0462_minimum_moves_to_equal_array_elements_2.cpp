class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int l=0,r=(int)nums.size()-1;l<r;l++,r--) ans+=((long long)nums[r]-nums[l]);
        return (int)ans;
    }
};
