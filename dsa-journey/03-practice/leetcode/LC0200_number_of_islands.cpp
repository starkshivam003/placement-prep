class Solution {
public:
    void sink(vector<vector<char>>& grid, int x,int y){
        int m=(int)grid.size(),n=(int)grid[0].size();
        char orig=grid[x][y];
        grid[x][y]='0';
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=m||nc>=n||nr<0||nc<0) continue;
                if(grid[nr][nc]=='0') continue;
                grid[nr][nc]='0';
                q.push({nr,nc});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    sink(grid,i,j);
                }
            }
        }
        return count;
    }
};
