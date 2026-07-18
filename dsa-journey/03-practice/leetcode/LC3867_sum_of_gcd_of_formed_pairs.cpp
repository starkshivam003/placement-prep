class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mxi=INT_MIN;
        vector<int> A;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]>mxi){
                mxi=nums[i];
            }
            if(mxi%nums[i]==0){
                A.push_back(nums[i]);
            }
            else if(mxi%nums[i]!=0){
                int mn=nums[i];
                int mx=mxi;
                while(mx%mn!=0){
                    int temp=mx;
                    mx=mn;
                    mn=temp%mn;
                }
                A.push_back(mn);
            }
        }
        std::sort(A.begin(),A.end());
        int i=0, j=(int)A.size()-1;
        long long sum=0;
        while(i<j){
            if(A[j]%A[i]==0){
                sum+=A[i];
            }
            else{
                while(A[j]%A[i]!=0){
                    int temp=A[j];
                    A[j]=A[i];
                    A[i]=temp%A[i];
                }
                sum+=A[i];
            }
            i++;
            j--;
        }
        return sum;
    }
};
