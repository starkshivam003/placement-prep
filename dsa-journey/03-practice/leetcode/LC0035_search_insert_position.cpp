class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if((int)nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            else if(nums[0]<target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int l=0, h=(int)nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        l=0, h=(int)nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target<nums[mid]){
                if(mid-1>-1&&(nums[mid]>target&&nums[mid-1]<target)){
                    return mid;
                }
                else if(mid-1==0){
                    return 0;
                }
                else{
                    h=mid-1;
                }
            }
            else{
                if(mid+1<(int)nums.size()&&(nums[mid]<target&&nums[mid+1]>target)){
                    return mid+1;
                }
                else if(mid+1==(int)nums.size()-1){
                    return (int)nums.size();
                }
                else{
                    l=mid+1;
                }
            }
        }
        return 0;
    }
};
