class Solution {
public:
    void f(int i,int j,vector<vector<int>>& grid,vector<long long>& area){
        int m=(int)grid.size(),n=(int)grid[0].size();
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        area.push_back((long long)grid[i][j]);
        grid[i][j]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(grid[nr][nc]){
                    area.back()+=(long long)grid[nr][nc];
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<long long> area;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) f(i,j,grid,area);
            }
        }
        int count=0;
        for(long long& a:area){
            if(a%k==0) count++;
        }
        return count;
    }
};


class Solution {
public:
    long long f(int i,int j,vector<vector<int>>& grid){
        int m=(int)grid.size(),n=(int)grid[0].size();
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        long long sum=grid[i][j];
        grid[i][j]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nr=x+dr[d],nc=y+dc[d];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(grid[nr][nc]){
                    sum+=grid[nr][nc];
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=(int)grid.size(),n=(int)grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&(f(i,j,grid)%k==0)) count++;
            }
        }
        return count;
    }
};
