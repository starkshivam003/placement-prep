class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=(int)nums.size();
        int prevsum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<n;i++){
            if(prevsum<0){
                prevsum=nums[i];
            }
            else{
                prevsum+=nums[i];
            }
            if(prevsum>maxsum){
                maxsum=prevsum;
            }
        }
        return maxsum;
    }
};
