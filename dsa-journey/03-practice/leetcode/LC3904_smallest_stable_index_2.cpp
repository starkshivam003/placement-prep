class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=(int)nums.size();
        vector<int> max_arr(n,-1);
        vector<int> min_arr(n,-1);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            max_arr[i]=maxi;
        }
        for(int i=n-1;i>-1;i--){
            mini=min(mini,nums[i]);
            min_arr[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(max_arr[i]-min_arr[i]<=k){
                return i;
            }
        }
        return -1;
    }
};
