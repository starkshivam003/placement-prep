/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=(int)matrix.size(),n=(int)matrix[0].size();
        int l=0,r=n-1,x=-1;
        int top=0,bot=m-1;
        while(top<=bot){
            int mid=top+((bot-top)/2);
            if(matrix[mid][0]>target){
                bot=mid-1;
            }
            else if(matrix[mid][n-1]<target){
                top=mid+1;
            }
            else{
                x=mid;
                break;
            }
        }
        if(x==-1) return false;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(matrix[x][mid]==target){
                return true;
            }
            else if(matrix[x][mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,m=(int)matrix.size(),n=(int)matrix[0].size(),r=m*n-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            int val=matrix[mid/n][mid%n];
            if(val==target) return true;
            else if(val<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};
