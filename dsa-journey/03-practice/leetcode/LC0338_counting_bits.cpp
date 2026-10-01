class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<n+1;i++){
            int res=0;
            int x=i;
            while(x){
                x&=(x-1);
                res++;
            }
            ans[i]=res;
        }
        return ans;
    }
};
