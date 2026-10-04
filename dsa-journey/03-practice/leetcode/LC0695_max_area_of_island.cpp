class Solution {
public:
    int maxArea(vector<vector<int>>& grid, int i, int j){
        int m=(int)grid.size(),n=(int)grid[0].size();
        int count=1;
        int orig=grid[i][j];
        grid[i][j]=0;
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int a=0;a<4;a++){
                int nr=x+dr[a],nc=y+dc[a];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(grid[nr][nc]==0) continue;
                count++;
                grid[nr][nc]=0;
                q.push({nr,nc});
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        int max_area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    max_area=max(max_area,maxArea(grid,i,j));
                }
            }
        }
        return max_area;
    }
};
