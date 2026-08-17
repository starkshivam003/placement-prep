class Solution {
    stack<char> stk;
    stack<long long> stkint;
    unordered_map<char,int> precedence;
public:
    Solution(){
        precedence['-']=1;
        precedence['+']=1;
        precedence['*']=3;
        precedence['/']=3;
    }
    int calculate(string s) {
        vector<string> ans;
        int n=(int)s.size();
        int i=0;
        while(i<n){
            if(s[i]==' '){ i++; continue; }
            if(s[i]>='0'&&s[i]<='9'){
                int j=i;
                while(j<n && s[j]>='0' && s[j]<='9') j++;
                ans.push_back(s.substr(i, j-i));
                i=j;
                continue;
            }
            else{
                while(!stk.empty()&&precedence[s[i]]<=precedence[stk.top()]){
                    ans.push_back(string(1, stk.top()));
                    stk.pop();
                }
                stk.push(s[i]);
                i++;
            }
        }
        while(!stk.empty()){
            ans.push_back(string(1, stk.top()));
            stk.pop();
        }

        for(auto &token : ans){
            if(token[0]>='0' && token[0]<='9'){
                stkint.push(stoll(token));
            }
            else{
                long long upper=stkint.top(); stkint.pop();
                long long bot=stkint.top(); stkint.pop();
                if(token[0]=='-') stkint.push(bot-upper);
                if(token[0]=='+') stkint.push(bot+upper);
                if(token[0]=='*') stkint.push(bot*upper);
                if(token[0]=='/') stkint.push(bot/upper);
            }
        }
        return (int)stkint.top();
    }
};
