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
class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>>& ans,vector<int>& a,int targetSum){
        if(!root) return;
        a.push_back(root->val);        
        if(!root->left&&!root->right){
            if(root->val==targetSum) ans.push_back(a);
        }
        else{
            helper(root->left,ans,a,targetSum-root->val);
            helper(root->right,ans,a,targetSum-root->val);
        }
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> a;
        helper(root,ans,a,targetSum);
        return ans;
    }
};
