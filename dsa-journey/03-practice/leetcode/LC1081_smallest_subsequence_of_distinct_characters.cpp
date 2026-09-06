class Solution {
public:
    string smallestSubsequence(string s) {
        int n=(int)s.size();
        string stk="";
        vector<int> lastidx(26,0);
        vector<bool> instk(26,false);
        for(int i=0;i<n;i++){
            lastidx[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            if(instk[c-'a']) continue;
            while(!stk.empty()&&stk.back()>c&&lastidx[stk.back()-'a']>i){
                instk[stk.back()-'a']=false;
                stk.pop_back();
            }
            stk+=c;
            instk[c-'a']=true;
        }
        return stk;
    }
};
