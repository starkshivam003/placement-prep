class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=(int)height.size()-1,water=0;
        while(l<r){
            water=max(water,(min(height[l],height[r])*(r-l)));
            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return water;
    }
};
