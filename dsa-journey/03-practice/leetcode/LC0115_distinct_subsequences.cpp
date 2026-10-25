class Solution {
public:
    unsigned f(const string& s,const string& t,int i,int j,vector<vector<unsigned>>& memo,vector<vector<bool>>& done){
        if(j==(int)t.size()) return 1;
        if(i==(int)s.size()) return 0;
        if(done[i][j]) return memo[i][j];
        unsigned ways=f(s,t,i+1,j,memo,done);
        if(s[i]==t[j]){
            ways+=f(s,t,i+1,j+1,memo,done);
        }
        done[i][j]=true;
        return memo[i][j]=ways;
    }
    int numDistinct(string s, string t) {
        int m=(int)s.size();
        int n=(int)t.size();
        vector<vector<unsigned>> memo(m+1,vector<unsigned>(n+1,0));
        vector<vector<bool>> done(m+1,vector<bool>(n+1,false));
        return (int)f(s,t,0,0,memo,done);
    }
};
