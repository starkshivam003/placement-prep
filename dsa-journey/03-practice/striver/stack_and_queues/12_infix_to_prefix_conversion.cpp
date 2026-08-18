class Solution {
    unordered_map<char,int> mpp;
public:
    Solution(){
        mpp['+']=1;
        mpp['-']=1;
        mpp['*']=2;
        mpp['/']=2;
        mpp[')']=0;
        mpp['(']=0;
    }
    string infixToPrefix(const string& s) {
        int n=(int)s.size();
        stack<char> stk;
        string ans="";
        for(int i=n-1;i>-1;i--){
            if(isalnum(s[i])){
                ans=string(1,s[i])+ans;
            }
            else{
                if(s[i]==')'){
                    stk.push(s[i]);
                }
                else if(s[i]=='('){
                    while(!stk.empty()&&stk.top()!=')'){
                        ans=string(1,stk.top())+ans;
                        stk.pop();
                    }
                    stk.pop();
                }
                else{
                    while(!stk.empty()&&stk.top()!=')'&&mpp[s[i]]<mpp[stk.top()]){
                        ans=string(1,stk.top())+ans;
                        stk.pop();
                    }
                    stk.push(s[i]);
                }
            }
        }
        while(!stk.empty()){
            ans=string(1,stk.top())+ans;
            stk.pop();
        }
        return ans;
    }
};
