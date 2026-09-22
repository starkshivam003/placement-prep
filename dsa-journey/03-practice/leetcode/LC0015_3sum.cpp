/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=(int)nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            mpp[nums[i]]--;
            if(i>0&&nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n;j++){
                mpp[nums[j]]--;
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int target=-(nums[i]+nums[j]);
                if(mpp[target]>0){
                    res.push_back({nums[i],nums[j],target});
                }
            }
            for(int j=i+1;j<n;j++){
                mpp[nums[j]]++;
            }
        }
        return res;
    }
};*/
/*class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n=(int)nums.size();
        set<vector<int>> stt;
        for(int i=0;i<n;i++){
            unordered_set<int> seen;
            for(int j=i+1;j<n;j++){
                int need=-(nums[i]+nums[j]);
                if(seen.count(need)){
                    vector<int> trip={nums[i],nums[j],need};
                    sort(trip.begin(),trip.end());
                    stt.insert(trip);
                }
                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(stt.begin(),stt.end());
    }
};*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=(int)nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
