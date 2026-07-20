class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        k%=(m*n);
        if(m==0 || n==0){
            return {};
        }
        if(k==0){
            return grid;
        }
        for(int a=0;a<k;a++){
            int tail=grid[0][0];
            int head=grid[0][0];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0&&j==0){
                        grid[0][0]=grid[m-1][n-1];
                        continue;
                    }
                    tail=head;
                    head=grid[i][j];
                    grid[i][j]=tail;
                }
            }            
        }
        return grid;
    }
};
