/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
public:
    void traverse(TreeNode* root,priority_queue<int>& pq,int k){
        if(root){
            pq.push(root->val);
            if((int)pq.size()>k) pq.pop();
            traverse(root->left,pq,k);
            traverse(root->right,pq,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        traverse(root,pq,k);
        return pq.top();
    }
};*/

class Solution {
public:
    void arr(TreeNode* root,int k,vector<int>& ans){
        if (!root || (int)ans.size() >= k) return;
        arr(root->left,k,ans);
        ans.push_back(root->val);
        if((int)ans.size()>=k) return;
        arr(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        arr(root,k,ans);
        return ans[k-1];
    }
};
