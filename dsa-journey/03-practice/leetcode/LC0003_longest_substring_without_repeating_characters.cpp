/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,ans=0;
        unordered_set<char> stt;
        for(int r=0;r<(int)s.size();r++){
            while(stt.find(s[r])!=stt.end()){
                stt.erase(s[l]);
                l++;
            }
            stt.insert(s[r]);
            ans=max(ans,(r-l+1));
        }
        return ans;
    }
};*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,res=0;
        unordered_map<char,int> mpp;
        for(int r=0;r<(int)s.size();r++){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(mpp[s[r]]+1,l);
            }
            mpp[s[r]]=r;
            res=max(res,r-l+1);
        }
        return res;
    }
};
