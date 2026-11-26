class Solution {
public:
    char help(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int l=0,r=(int)s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return help(s, l+1, r) || help(s, l, r-1);
            }
            r--;
            l++;
        }
        return true;
    }
};
