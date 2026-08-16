class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int> NSE;
        stack<int> stk;
        for(int i=0;i<(int)arr.size();i++){
            while(!stk.empty()&&stk.top()>arr[i]){
                NSE[stk.top()]=arr[i];
                stk.pop();
            }
            stk.push(arr[i]);
        }
        for(int i=0;i<(int)arr.size();i++){
            ans.push_back(NSE.count(arr[i])?(NSE[arr[i]]):-1);
        }
        return ans;
    }
};
