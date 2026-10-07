class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=(int)graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int& v:graph[x]){
                        if(color[v]==-1){
                            color[v]=1-color[x];
                            q.push(v);
                        }
                        else if(color[v]==color[x]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
