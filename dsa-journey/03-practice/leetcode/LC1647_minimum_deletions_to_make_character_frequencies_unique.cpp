class Solution {
public:
    int minDeletions(string s) {
        array<int,26> cnt={0};
        int ans=0;
        for(const char& c:s){
            cnt[c-'a']++;
        }
        unordered_set<int> taken;
        for(int c:cnt){
            while(c>0&&taken.count(c)){
                c--;
                ans++;
            }
            if(c>0) taken.insert(c);
        }
        return ans;
    }
};
