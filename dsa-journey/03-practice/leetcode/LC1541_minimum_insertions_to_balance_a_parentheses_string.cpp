class Solution {
public:
    int minInsertions(string s) {
        int open=0,add=0,i=0;
        for(i=0;i<(int)s.size();i++){
            if(s[i]=='(') open++;
            else{
                if(i+1<(int)s.size()&&s[i+1]==')') i++;
                else add++;
                if(open>0) open--;
                else add++;
            }
        }
        return (2*open)+add;
    }
};
