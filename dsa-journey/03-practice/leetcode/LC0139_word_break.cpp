class Solution {
public:
    bool f(int i,vector<int>& memo,unordered_set<string>& dict,const string& s){
        int n=(int)s.size();
        if(i==n) return true;
        if(memo[i]!=-1) return memo[i];
        for(int j=i;j<n;j++){
            string word=s.substr(i,j-i+1);
            if(dict.count(word)&&f(j+1,memo,dict,s)) return memo[i]=1;
        }
        return memo[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=(int)s.size();
        vector<int> memo(n,-1);
        return f(0,memo,dict,s);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=(int)s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        int idx=n;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                string word=s.substr(i,j-i+1);
                if(dict.count(word)&&dp[j+1]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};
