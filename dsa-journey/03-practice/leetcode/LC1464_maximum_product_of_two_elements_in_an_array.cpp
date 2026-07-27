class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==2){
            return (nums[0]-1)*(nums[1]-1);
        }
        int k[2]={INT_MIN,INT_MIN};
        for(int i=0;i<n;i++){
            if(nums[i]>k[0]){
                k[1]=k[0];
                k[0]=nums[i];
            }
            else if(nums[i]<=k[0]&&nums[i]>k[1]){
                k[1]=nums[i];
            }
        }
        return (k[0]-1)*(k[1]-1);
    }
};
