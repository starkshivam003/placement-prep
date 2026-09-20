class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<(int)s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<(int)t.size();i++){
            mpp[t[i]]--;
        }
        for(auto& key: mpp){
            if(key.second!=0){
                return false;
            }
        }
        return true;
    }
};
