class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=(int)obstacleGrid.size(),n=(int)obstacleGrid[0].size();
        vector<int> ans(n,0);
        ans[0]=1;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) ans[0]=0;
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) ans[j]=0;
                else ans[j]+=ans[j-1];
            }
        }
        return ans[n-1];
    }
};
