class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> look(maxi+1,0);
        for(int& num:nums){
            look[num]+=num;
        }
        int a=0,b=0;
        for(int i=maxi;i>=0;i--){
            int c=max(look[i]+b,a);
            b=a;
            a=c;
        }
        return a;
    }
};
