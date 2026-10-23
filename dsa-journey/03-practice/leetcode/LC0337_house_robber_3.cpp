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
    pair<int,int> f(TreeNode* root){
        if(!root) return {0,0};
        auto [lr,lnr]=f(root->left);
        auto [rr,rnr]=f(root->right);
        int r=root->val+lnr+rnr;
        int nr=max(lr,lnr)+max(rr,rnr);
        return {r,nr};
    }
    int rob(TreeNode* root) {
        auto [r,nr]=f(root);
        return max(r,nr);
    }
};
