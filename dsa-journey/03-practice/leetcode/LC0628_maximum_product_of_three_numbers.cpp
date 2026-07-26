class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi[3]={INT_MIN,INT_MIN,INT_MIN};
        int mini[3]={INT_MAX,INT_MAX,INT_MAX};
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]>=maxi[0]){
                maxi[2]=maxi[1];
                maxi[1]=maxi[0];
                maxi[0]=nums[i];
            }
            else if(nums[i]<maxi[0]&&nums[i]>=maxi[1]){
                maxi[2]=maxi[1];
                maxi[1]=nums[i];
            }
            else if(nums[i]<maxi[1]&&nums[i]>maxi[2]){
                maxi[2]=nums[i];
            }
        }
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]<=mini[0]){
                mini[2]=mini[1];
                mini[1]=mini[0];
                mini[0]=nums[i];
            }
            else if(nums[i]>mini[0]&&nums[i]<=mini[1]){
                mini[2]=mini[1];
                mini[1]=nums[i];
            }
            else if(nums[i]>mini[1]&&nums[i]<mini[2]){
                mini[2]=nums[i];
            }
        }
        long long prod1 = (long long)mini[0]*mini[1]*maxi[0];
        long long prod2 = (long long)maxi[0]*maxi[1]*maxi[2];
        return (int)(prod1>prod2?prod1:prod2);
    }
};
