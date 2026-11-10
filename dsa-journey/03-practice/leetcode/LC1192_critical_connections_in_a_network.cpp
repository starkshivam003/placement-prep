class Solution {
public:
    void dfs(int u,int parent,const vector<vector<int>>& adj,vector<vector<int>>& ans,vector<int>& tin,vector<int>& low,int& timer){
        tin[u]=timer;
        low[u]=timer++;
        for(int v:adj[u]){
            if(v==parent) continue;
            if(tin[v]==-1){
                dfs(v,u,adj,ans,tin,low,timer);
                low[u]=min(low[u],low[v]);
                if(low[v]>tin[u]) ans.push_back({u,v});
            }
            else low[u]=min(low[u],tin[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(vector<int> c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n,-1),low(n,-1);
        int timer=0;
        dfs(0,-1,adj,ans,tin,low,timer);
        return ans;
    }
};
