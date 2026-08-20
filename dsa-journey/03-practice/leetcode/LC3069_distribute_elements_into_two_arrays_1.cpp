class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int last1=nums[0],last2=nums[1];
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        for(int i=3;i<=(int)nums.size();i++){
            if(last1>last2){
                last1=nums[i-1];
                arr1.emplace_back(last1);
            }
            else{
                last2=nums[i-1];
                arr2.emplace_back(last2);
            }
        }
        for(int i=0;i<(int)arr2.size();i++){
            arr1.emplace_back(arr2[i]);
        }
        return arr1;
    }
};
