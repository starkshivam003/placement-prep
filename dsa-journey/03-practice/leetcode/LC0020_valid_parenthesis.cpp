/*class Solution {
public:
    bool isValid(string s) {
        int n=0;
        for(int i=0;s[i]!='\0';i++){
            n++;
        }
        if(n==0){
            return true;
        }
        char A[n];
        int top=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                top++;
                A[top]=s[i];
            }
            else{
                if(top==-1){
                    return false;
                }
                else if(s[i]==')'&& A[top]=='('){
                    top--;
                }
                else if(s[i]==')'&& A[top]!='('){
                    return false;
                }
                else if(s[i]==']'&& A[top]=='['){
                    top--;
                }
                else if(s[i]==']'&& A[top]!='['){
                    return false;
                }
                else if(s[i]=='}'&& A[top]=='{'){
                    top--;
                }
                else if(s[i]=='}'&& A[top]!='{'){
                    return false;
                }

            }
        }
        if(top<0){
            return true;
        }
        return false;
    }
};*/
class Solution {
public:
    bool isValid(string s) {
        if((int)s.size()%2) return false;
        string stk;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                stk.push_back(c);
            }
            else{
                if(stk.empty()) return false;
                char d=stk.back();
                stk.pop_back();
                if((c==')'&&d!='(')||(c=='}'&&d!='{')||(c==']'&&d!='[')) return false;
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
