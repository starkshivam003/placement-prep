class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=(int)nums.size();
        k=k%n;
        if(k<n){
            vector<int> A(n);
            int j=0;
            for(int i=(n-k);i<n;i++){
                A[j++]=nums[i];
            }
            for(int i=0;i<(n-k);i++){
                A[j++]=nums[i];
            }
            for(int i=0;i<n;i++){
                nums[i]=A[i];
            }
        }
        
    }
};
