class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=x+dr[i],nc=y+dc[i];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(grid[nr][nc]!=1||dist[nr][nc]!=-1) continue;
                dist[nr][nc]=dist[x][y]+1;
                q.push({nr,nc});
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(dist[i][j]==-1) return -1;
                    ans=max(ans,dist[i][j]);
                }
            }
        }
        return ans;
    }
};
