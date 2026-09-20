/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=(int)nums.size();
        if(n<2){
            return false;
        }
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<(n-1);i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> stt;
        for(int i=0;i<(int)nums.size();i++){
            if(stt.find(nums[i])!=stt.end()){
                return true;
            }
            stt.insert(nums[i]);
        }
        return false;
    }
};
