class Solution {
private:
    unordered_map<char,int> out_stack_pre;
    unordered_map<char,int> in_stack_pre;
    stack<char> stk;
public:
    Solution(){
       out_stack_pre['+']=1;
       out_stack_pre['-']=1;
       out_stack_pre['*']=3;
       out_stack_pre['/']=3;
       out_stack_pre['^']=6;
       out_stack_pre['(']=7;
       out_stack_pre[')']=0;

       in_stack_pre['+']=2;
       in_stack_pre['-']=2;
       in_stack_pre['*']=4;
       in_stack_pre['/']=4;
       in_stack_pre['^']=5;
       in_stack_pre['(']=0;
       in_stack_pre[')']=-1;
    }
    string infixToPostfix(string s) {
        string ans="";
        int n=(int)s.size();
        for(int i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                ans+=s[i];
            }
            else{
                while(!stk.empty()&&out_stack_pre[s[i]]<=in_stack_pre[stk.top()]){
                    if(s[i]==')'&&stk.top()=='('){
                        stk.pop();
                        break;
                    }
                    ans+=stk.top();
                    stk.pop();
                }
                if(s[i]!=')'){
                    stk.push(s[i]);
                }
            }
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};
