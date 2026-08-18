class Solution {
public:
    string postToPre(string postfix) {
        stack<string> stk;
        int n=(int)postfix.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans="";
            if(isalnum(postfix[i])){
                stk.push(string(1,postfix[i]));
            }
            else{
                string right=stk.top();
                stk.pop();
                string left=stk.top();
                stk.pop();
                ans+=string(1,postfix[i])+left+right;
                stk.push(ans);
            }
        }
        return stk.top();
    }
};
