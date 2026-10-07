class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inw(n,false);
        for(vector<int>& e:edges){
            inw[e[1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!inw[i]) ans.push_back(i);
        }
        return ans;
    }
};
