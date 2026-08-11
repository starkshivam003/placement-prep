class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==1){
            return nums[0]+1;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=(nums[i-1]+1)){
                break;
            }
            else{
                sum+=nums[i];
            }
        }
        if(sum>50){
            return sum;
        }
        int B[51]={0};
        for(int j=0;j<n;j++){
            B[nums[j]]++;
        }
        for(int j=0;j<51;j++){
            if(j>=sum&&B[j]==0){
                return j;
            }
        }
        return 51;
    }
};
