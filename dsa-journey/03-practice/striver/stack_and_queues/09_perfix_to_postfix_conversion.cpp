class Solution {
public:
    string prefixToPostfix(const string& s) {
        stack<string> stk;
        string ans="";
        int n=(int)s.size();
        for(int i=n-1;i>-1;i--){
            ans="";
            if(isalnum(s[i])){
                stk.push(string(1,s[i]));
            }
            else{
                ans+=stk.top();
                stk.pop();
                ans+=stk.top();
                stk.pop();
                ans+=string(1,s[i]);
                stk.push(ans);
            }
        }
        return stk.top();
    }
};
