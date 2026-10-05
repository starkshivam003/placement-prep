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
    bool isit(TreeNode* root,int targetSum,int sum){
        if(!root) return false;
        sum+=root->val;
        if(!root->left&&!root->right) return sum==targetSum;
        return isit(root->left,targetSum,sum)||isit(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isit(root,targetSum,0);
    }
};*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left&&!root->right) return root->val==targetSum;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
};
