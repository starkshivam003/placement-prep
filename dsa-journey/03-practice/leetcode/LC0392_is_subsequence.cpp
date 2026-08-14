class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=(int)s.size();
        int m=(int)t.size();
        if(n>m){
            return false;
        }
        if(n==m){
            for(int i=0;i<n;i++){
                if(s[i]!=t[i]){
                    return false;
                }
            }
        }
        if(n<m){
            int j=0;
            for(int i=0;i<n;i++){
                int flag=0;
                while(j<m){
                    if(t[j]==s[i]){
                        flag=1;
                        j++;
                        break;
                    }
                    j++;
                }
                if(flag==0){
                    return false;
                }
            }
        }
        return true;
    }
};
