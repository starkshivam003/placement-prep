class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=(int)matrix.size(),n=(int)matrix[0].size();
        int r=0,c=n-1;
        while(r<m&&c>-1){
            int val=matrix[r][c];
            if(val==target) return true;
            else if(val>target) c--;
            else r++;
        }
        return false;
    }
};
