class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=(int)piles.size();
        int maxi=*max_element(piles.begin(),piles.end());
        if(n==h) return maxi;
        int l=1,r=maxi,res=0;
        while(l<=r){
            int s=l+((r-l)/2);
            long long time=0;
            for(int& p:piles){
                time+=(p+s-1)/s;
            }
            if(time<=h){
                res=s;
                r=s-1;
            }
            else l=s+1;
        }
        return res;
    }
};
