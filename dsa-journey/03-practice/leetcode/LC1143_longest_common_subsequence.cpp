class Solution {
public:
    int f(int i,int j,vector<vector<int>>& memo,string& text1,string& text2){
        if(i<0||j<0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(text1[i]==text2[j]) memo[i][j]=1+f(i-1,j-1,memo,text1,text2);
        else memo[i][j]=max(f(i-1,j,memo,text1,text2),f(i,j-1,memo,text1,text2));
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=(int)text1.size();
        int n=(int)text2.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return f(m-1,n-1,memo,text1,text2);
    }
};
