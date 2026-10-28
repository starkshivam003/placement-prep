class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string d(n,'.');
        ans.push_back(d);
        string s(n-1,'#');
        s+='.';
        for(int i=1;i<m;i++){
            ans.push_back(s);
        }
        return ans;
    }
};
