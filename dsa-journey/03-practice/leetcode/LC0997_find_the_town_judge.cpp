class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> ans(n+1,false);
        vector<int> ansa(n+1,0);
        for(vector<int>& t:trust){
            ans[t[0]]=true;
            ansa[t[1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(!ans[i]&&ansa[i]==n-1) return i;
        }
        return -1;
    }
};
