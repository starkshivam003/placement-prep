class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int l=0,ans=0,maxf=0;
        for(int r=0;r<(int)s.size();r++){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while(((r-l+1)-maxf)>k){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
