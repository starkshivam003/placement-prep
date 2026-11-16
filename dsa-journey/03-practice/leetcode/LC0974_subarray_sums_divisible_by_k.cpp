class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=(int)nums.size();
        vector<int> grp(k,0);
        grp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            grp[(sum%k+k)%k]++;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=(grp[i]*(grp[i]-1))/2;
        }
        return ans;
    }
};
