class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=(int)isConnected.size();
        int ans=0;
        vector<bool> visit(n,false);
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            ans++;
            queue<int> q;
            q.push(i);
            visit[i]=true;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(isConnected[x][j]==1&&!visit[j]){
                        visit[j]=true;
                        q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};
