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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> A;
        inorder(root,A);
        return A;
    }
    void inorder(TreeNode *t,vector<int>& A){
        if(!t){
            return ;
        }
        inorder(t->left,A);
        A.push_back(t->val);
        inorder(t->right,A);
    }
};
