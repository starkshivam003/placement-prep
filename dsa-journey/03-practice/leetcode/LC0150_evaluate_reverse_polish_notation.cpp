class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int r,l;
        for(string& c:tokens){
            if(c=="+"||c=="-"||c=="*"||c=="/"){
                r=stk.top();
                stk.pop();
                l=stk.top();
                stk.pop();
                if(c=="+") stk.push(l+r);
                if(c=="-") stk.push(l-r);
                if(c=="*") stk.push(l*r);
                if(c=="/") stk.push(l/r);
            }
            else{
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};
