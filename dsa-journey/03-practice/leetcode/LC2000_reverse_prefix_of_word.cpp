class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=(int)word.size();
        int i=0;
        while(i<n){
            if(word[i]==ch){
                i++;
                break;
            }
            i++;
        }
        if(i==n&&word[i-1]!=ch){
            return word;
        }
        reverse(word.begin(),word.begin()+i);
        return word;
    }
};
