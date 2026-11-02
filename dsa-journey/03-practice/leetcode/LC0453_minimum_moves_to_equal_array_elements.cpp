class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        long long moves=0;
        for(const int& num:nums) moves+=(abs((long long)mini-num));
        return (int)moves;
    }
};
