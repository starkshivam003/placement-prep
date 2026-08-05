class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=(int)s.size();
        int j=n-1;
        int count=0;
        int flag=0;
        if(s[j]!=' ') flag=2;
        while(flag==0){
            if(s[j]!=' '){
                flag=1;
                break;
            }
            j--;
        }
        while(j>-1&&s[j]!=' '){
            count++;
            j--;
        }
        return count;
    }
};
