class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=(int)numbers.size()-1;
        while(l<r){
            int tmp=numbers[r]+numbers[l];
            if(tmp>target){
                r--;
            }
            else if(tmp<target){
                l++;
            }
            else{
                return {l+1,r+1};
            }
        }
        return {};
    }
};
