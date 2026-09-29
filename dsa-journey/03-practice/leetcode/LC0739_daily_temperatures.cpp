class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=(int)temperatures.size();
        vector<int> ans(n,0);
        vector<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty()&&temperatures[stk.back()]<temperatures[i]){
                ans[stk.back()]=i-stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return ans;
    }
};
