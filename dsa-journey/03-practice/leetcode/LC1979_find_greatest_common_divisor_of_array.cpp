class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        if(maxi%mini==0){
            return mini;
        }
        while(maxi%mini!=0){
            int temp = maxi;
            maxi=mini;
            mini=temp%mini;
        }
        return mini;
    }
};
