class Solution {
public:
    void helper(int m,int n,int dr[],int dc[],int& path,int i,int j){
        if(i==m-1&&j==n-1) path++;
        for(int k=0;k<2;k++){
            int nr=i+dr[k],nc=j+dc[k];
            if(nr<0||nc<0||nr>=m||nc>=n) continue;
            helper(m,n,dr,dc,path,nr,nc);
        }
    }
    int uniquePaths(int m, int n) {
        int dr[2]={1,0},dc[2]={0,1};
        int path=0;
        helper(m,n,dr,dc,path,0,0);
        return path;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            ans[0][i]=1;
        }
        for(int i=0;i<m;i++){
            ans[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res=1;
        int N=m+n-2,k=min(m-1,n-1);
        for(int i=1;i<=k;i++){
            res=res*(N-k+i)/i;
        }
        return int(res);
    }
};
