class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0]=1;
        int dr[8]={1,-1,0,0,1,1,-1,-1},dc[8]={0,0,1,-1,1,-1,1,-1};
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            if(x==m-1&&y==n-1) return dist[x][y];
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dr[i],ny=y+dc[i];
                if(nx>=m||nx<0||ny>=n||ny<0) continue;
                if(grid[nx][ny]==1||dist[nx][ny]!=-1) continue;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        return dist[m-1][n-1];
    }
};
