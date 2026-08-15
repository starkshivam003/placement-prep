/*
//attempt1: time - O(n^2) and space - O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<(int)nums1.size();i++){
            q.push(nums1[i]);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int i;
            for(i=0;i<(int)nums2.size();i++){
                if(nums2[i]==x){
                    break;
                }
            }
            i++;
            if(i==(int)nums2.size()){
                ans.push_back(-1);
                continue;
            }
            while(i<(int)nums2.size()){
                if(nums2[i]>x){
                    ans.push_back(nums2[i]);
                    break;
                }
                i++;
            }
            if(i==(int)nums2.size()){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
*/
//attempt 2: time - O(n) and space - O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        unordered_map<int,int> nextG;
        
        for(int i=0;i<(int)nums2.size();i++){
            while(!s.empty()&&s.top()<nums2[i]){
                nextG[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<(int)nums1.size();i++){
            ans.push_back(nextG.count(nums1[i])?nextG[nums1[i]]:-1);
        }
        return ans;
    }
};
