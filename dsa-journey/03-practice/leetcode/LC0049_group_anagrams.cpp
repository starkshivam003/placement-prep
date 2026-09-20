class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto& s: strs){
            int count[26]={0};
            for(char c: s){
                count[c-'a']++;
            }
            string key;
            for(int i=0;i<26;i++){
                key+='#';
                key+=string(1,count[i]);
            }
            mpp[key].emplace_back(s);
        }
        vector<vector<string>> res;
        for(auto& [key,grp]:mpp){
            res.emplace_back(grp);
        }
        return res;
    }
};
