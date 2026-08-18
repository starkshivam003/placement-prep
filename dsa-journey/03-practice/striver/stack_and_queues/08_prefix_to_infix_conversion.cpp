class Solution {
public:
    string prefixToInfix(string s) {
        int n=(int)s.size();
        string ans="";
        stack<string> stk;
        for(int i=(n-1);i>-1;i--){
            ans="";
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                stk.push(string(1,s[i]));
            }
            else{
                string left=stk.top();
                stk.pop();
                string right=stk.top();
                stk.pop();
                ans="("+left+string(1,s[i])+right+")";
                stk.push(ans);
            }
        }
        return stk.top();
    }
};
