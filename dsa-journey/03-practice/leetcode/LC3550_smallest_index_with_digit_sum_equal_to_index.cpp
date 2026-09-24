class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=(int)nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            int digsum=0;
            while(x>0){
                digsum+=(x%10);
                x/=10;
            }
            if(digsum==i) return i;
        }
        return -1;
    }
};
