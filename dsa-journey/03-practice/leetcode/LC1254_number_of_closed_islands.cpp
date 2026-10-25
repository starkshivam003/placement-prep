class Solution {
public:
    void help(vector<vector<int>>& grid,int i,int j){
        int m=(int)grid.size(),n=(int)grid[0].size();
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        grid[i][j]=2;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(grid[nr][nc]==0){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[0][i]==0) help(grid,0,i);
            if(grid[m-1][i]==0) help(grid,m-1,i);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==0) help(grid,i,0);
            if(grid[i][n-1]==0) help(grid,i,n-1);
        }
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    help(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
