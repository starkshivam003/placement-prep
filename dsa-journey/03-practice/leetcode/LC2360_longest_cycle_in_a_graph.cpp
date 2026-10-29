class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=(int)edges.size();
        vector<int> indig(n,0);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                indig[edges[i]]++;
            }
        }
        vector<char> removed(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indig[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            removed[u]=1;
            int v=edges[u];
            if(v!=-1&&--indig[v]==0) q.push(v);
        }
        vector<char> visited(n,0);
        int best=-1;
        for(int s=0;s<n;s++){
            if(removed[s]||visited[s]) continue;
            int v=s;
            int len=0;
            do{
                len++;
                visited[v]=1;
                v=edges[v];
            } while(v!=s);
            best=max(best,len);
        }
        return best;
    }
};
