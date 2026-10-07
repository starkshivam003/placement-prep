class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(vector<int>& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long total = (long long)n * (n - 1) / 2;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                long long size=1;
                queue<int> q;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int& v:adj[x]){
                        if(!visited[v]){
                            visited[v]=true;
                            size++;
                            q.push(v);
                        }
                    }
                }
                total -= size * (size - 1) / 2;
            }
        }
        return total;
    }
};
