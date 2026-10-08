class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indig(numCourses,0);
        for(vector<int>& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indig[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indig[i]) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int& v:adj[u]){
                indig[v]--;
                if(indig[v]==0) q.push(v);
            }
        }
        if((int)ans.size()!=numCourses) return {};
        return ans;
    }
};
