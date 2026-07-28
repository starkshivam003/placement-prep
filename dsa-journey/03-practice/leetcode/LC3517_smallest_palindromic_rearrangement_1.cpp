class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n==1){
            return s;
        }
        string sub(n,' ');
        int A[26]={0};
        int i=0,j=(n-1);
        for(int k=0;k<n;k++){
            A[s[k]-'a']++;
        }
        for(int k=0;k<26;k++){
            if(A[k]>1){
                while(A[k]>1&&(i<j)){
                    sub[i]=k+97;
                    sub[j]=k+97;
                    i++;
                    j--;
                    A[k]-=2;
                }
            }
        }
        if(i==j){
            for(int k=0;k<26;k++){
                if(A[k]>0){
                    sub[i]=k+97;
                    break;
                }
            }
        }
        return sub;
    }
};
