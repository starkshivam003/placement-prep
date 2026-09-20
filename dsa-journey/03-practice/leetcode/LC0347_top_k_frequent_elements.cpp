/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int n:nums) mpp[n]++;

        vector<pair<int,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](auto& a,auto& b){return a.second>b.second;});
        vector<int> result;
        for(int i=0;i<k;i++){
            result.emplace_back(v[i].first);
        }
        return result;
    }
};
*/
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int n:nums) mpp[n]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> mnhp;
        for(auto& [key,value]:mpp){
            mnhp.push({value,key});
            if(mnhp.size()>k) mnhp.pop();
        }

        vector<int> result;
        while(!mnhp.empty()){
            result.emplace_back(mnhp.top().second);
            mnhp.pop();
        }
        return result;
    }
};
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int n:nums) mpp[n]++;

        int n=(int)nums.size();
        vector<vector<int>> buck(n+1);
        for(auto& [key,value]:mpp){
            buck[value].emplace_back(key);
        }

        vector<int> result;
        for(int i=n;i>0&&result.size()<k;i--){
            for(auto& val:buck[i]){
                result.emplace_back(val);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};
