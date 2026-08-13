//method 1: recursion - O(2^(m+n)) time and O(m+n) space
/*class Solution {
public:
    int r, c;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i==r-1 && j==c-1) return grid[i][j];
        if(i==r-1) return grid[i][j] + solve(i, j+1, grid);
        if(j==c-1) return grid[i][j] + solve(i+1, j, grid);
        return grid[i][j] + min(solve(i+1,j,grid), solve(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        return solve(0, 0, grid);
    }
};*/

//method 2: recursion with meomization - O(mn) time and O(mn)+O(m+n) space
/*class Solution {
public:
    int r, c;
    vector<vector<int>> memo;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(memo[i][j] != -1) return memo[i][j];
        int result;
        if(i==r-1 && j==c-1) result = grid[i][j];
        else if(i==r-1) result = grid[i][j] + solve(i, j+1, grid);
        else if(j==c-1) result = grid[i][j] + solve(i+1, j, grid);
        else result = grid[i][j] + min(solve(i+1,j,grid), solve(i,j+1,grid));
        memo[i][j] = result;
        return result;
    }
    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        memo.assign(r, vector<int>(c, -1));
        return solve(0, 0, grid);
    }
};*/


//method 3: tabularisation - O(mn) time and O(mn) space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=(int)grid.size();
        int c=(int)grid[0].size();
        vector<vector<int>> A(r,vector<int>(c,-1));
        for(int i=(r-1);i>-1;i--){
            for(int j=(c-1);j>-1;j--){
                if(i==(r-1)&&j==(c-1)){
                    A[i][j]=grid[i][j];
                }
                if(i==(r-1)&&j<(c-1)){
                    A[i][j]=grid[i][j]+A[i][j+1];
                }
                if(j==(c-1)&&i<(r-1)){
                    A[i][j]=grid[i][j]+A[i+1][j];
                }
                if(i<(r-1)&&j<(c-1)){
                    A[i][j]=grid[i][j]+min(A[i+1][j],A[i][j+1]);
                }
            }
        }
        return A[0][0];
    }
};

// tabularisation with optimisation - O(mn) time and O(n) space
/*class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> row(c);

        row[c-1] = grid[r-1][c-1];
        for(int j=c-2; j>=0; j--){
            row[j] = grid[r-1][j] + row[j+1];
        }

        for(int i=r-2; i>=0; i--){
            row[c-1] = grid[i][c-1] + row[c-1]; 
            for(int j=c-2; j>=0; j--){
                row[j] = grid[i][j] + min(row[j], row[j+1]);
            }
        }
        return row[0];
    }
};*/
