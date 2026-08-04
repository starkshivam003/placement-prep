class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=(int)nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        vector<int> A((maxi-mini)+1);
        for(int i=0;i<n;i++){
            A[nums[i]-mini]=1;
        }
        vector<int> B;
        for(int i=1;i<(maxi-mini);i++){
            if(A[i]==0&&i<(maxi-mini)){
                B.push_back(i+mini);
            }
        }
        return B;
    }
};
