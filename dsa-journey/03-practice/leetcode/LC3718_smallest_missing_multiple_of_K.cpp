//attempt 1: naive solution for the problem.
/*class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int A[101]={0};
        int maxi=INT_MIN;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]%k==0){
                A[nums[i]]++;
            }
            if(nums[i]>maxi&&nums[i]%k==0){
                maxi=nums[i];
            }
        }
        for(int i=1;i<101;i++){
            if(i%k==0&&A[i]==0){
                return i;
            }
        }
        return maxi+k;
    }
};*/
//attempt 2: general and best solution for the problem
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());
        for (int m = k; ; m += k) {
            if (present.find(m) == present.end()) {
                return m;
            }
        }
    }
};
