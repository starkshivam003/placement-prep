class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> stt(nums.begin(),nums.end());
        int n=(int)nums.size();
        int maxi=0;
        for(int num:stt){
            int l=0;
            if(stt.find(num-1)==stt.end()){
                while(stt.find(num+l)!=stt.end()){
                    l++;
                }
                maxi=max(maxi,l);
            }
        }
        return maxi;
    }
};
