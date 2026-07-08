class Solution {
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
};
