class Solution {
public:
    int f(int i,const vector<vector<int>>& child,const string& s,int& ans){
        int b1=0,b2=0;
        for(int c:child[i]){
            int len=f(c,child,s,ans);
            if(s[i]==s[c]) continue;
            if(len>b1){
                b2=b1;
                b1=len;
            }
            else if(len>b2) b2=len;
        }
        ans=max(ans,1+b1+b2);
        return 1+b1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=(int)parent.size();
        vector<vector<int>> child(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
        int ans=0;
        f(0,child,s,ans);
        return ans;
    }
};
