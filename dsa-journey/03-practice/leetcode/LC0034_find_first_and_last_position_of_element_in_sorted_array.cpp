class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int inde=0;
        if(nums.size()==0){
            return {-1,-1};
        }
        if(nums.size()==1 && nums[0]==target){
            return {0,0};
        }
        int l=0, h=(nums.size()-1);
        while(l<=h){
            int mid=l+((h-l)/2);
            if(nums[mid]==target){
                inde=mid;
                break;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(l>h){
            return {-1,-1};
        }
        else{
            int i=-1,j=1;
            while((inde+i>-1) && nums[inde+i]==target){
                i--;
            }
            while(((inde+j)<(int)nums.size()) && nums[inde+j]==target){
                j++;
            }
            return {inde+i+1,inde+j-1};
        }
        return {-1,-1};
    }
};
