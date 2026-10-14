class Solution {
public:
    void image(vector<vector<int>>& grid,int dr[],int dc[],queue<pair<int,int>>& q,int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1) return;
        grid[i][j]=2;
        q.push({i,j});
        for(int d=0;d<4;d++){
            image(grid,dr,dc,q,i+dr[d],j+dc[d],m,n);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        bool found=false;
        int steps=0;
        for(int i=0;i<m&&!found;i++){
            for(int j=0;j<n&&!found;j++){
                if(grid[i][j]==1){
                    image(grid,dr,dc,q,i,j,m,n);
                    found=true;
                }
            }
        }
        while(!q.empty()){
            int sz=(int)q.size();
            for(int i=0;i<sz;i++){
                auto [u,v]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=u+dr[k],nc=v+dc[k];
                    if(nr<0||nc<0||nr>=m||nc>=n) continue;
                    if(grid[nr][nc]==1) return steps;
                    if(grid[nr][nc]==0){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
