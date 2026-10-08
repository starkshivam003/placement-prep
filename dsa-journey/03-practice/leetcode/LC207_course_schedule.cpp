class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int taken=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            taken++;
            for(int& v:adj[x]){
                indig[v]--;
                if(indig[v]==0) q.push(v);
            }
        }
        return taken==numCourses;
    }
};
