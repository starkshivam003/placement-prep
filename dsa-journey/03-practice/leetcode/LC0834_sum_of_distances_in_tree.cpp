class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const vector<int>& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> order,p(n,-1),dist(n,-1);
        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            order.push_back(u);
            for(int v:adj[u]){
                if(dist[v]==-1){
                    dist[v]=1+dist[u];
                    p[v]=u;
                    q.push(v);
                }
            }
        }
        vector<int> sz(n,1);
        for(int k=n-1;k>0;k--){
            int u=order[k];
            sz[p[u]]+=sz[u];
        }
        vector<int> answer(n,0);
        for(int d:dist) answer[0]+=d;
        for(int i=1;i<n;i++){
            int u=order[i];
            answer[u]=(answer[p[u]]+n-2*sz[u]);
        }
        return answer;
    }
};
