class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string s:strs){
            result+=s;
            result+="#";
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0,n=(int)s.size();
        while(i<n){
            string res;
            int j=i;
            while(s[j]!='#'){
                res+=s[j++];
            }
            result.push_back(res);
            i=j+1;
        }
        return result;
    }
};
