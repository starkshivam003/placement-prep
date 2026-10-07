class Solution {
public:
    void helper(int node,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& path){
        path.push_back(node);
        if(path.back()==(int)graph.size()-1) ans.push_back(path);
        for(int& n:graph[node]){
            helper(n,graph,ans,path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(0,graph,ans,path);
        return ans;
    }
};
