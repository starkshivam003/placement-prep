class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<bool> visit(n,false);
        queue<int> q;
        q.push(source);
        visit[source]=true;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int& u:adj[v]){
                if(!visit[u]){
                    visit[u]=true;
                    q.push(u);
                }
            }
        }
        if(visit[destination]) return true;
        return false;
    }
};
