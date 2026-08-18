class Solution {
public:
    string postToInfix(string postExp) {
        stack<string> stk;
        int n=(int)postExp.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans="";
            if(isalnum(postExp[i])){
                stk.push(string(1,postExp[i]));
            }
            else{
                string right=stk.top();
                stk.pop();
                string left=stk.top();
                stk.pop();
                ans+="("+left+string(1,postExp[i])+right+")";
                stk.push(ans);
            }
        }
        return stk.top();
    }
};
