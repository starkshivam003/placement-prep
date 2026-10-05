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
    int mini=INT_MAX;
    void dep(TreeNode* root,int d){
        if(!root) return;
        if(!root->left&&!root->right) mini=min(mini,d);
        dep(root->left,1+d);
        dep(root->right,1+d);
    }
    int minDepth(TreeNode* root) {
        int d=0;
        dep(root,1+d);
        return mini==INT_MAX?0:mini;
    }
};
