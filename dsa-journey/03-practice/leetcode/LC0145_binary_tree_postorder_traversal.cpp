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
    stack<int> stk;
    void traverse(TreeNode* root,vector<int> &A){
        if(root!=NULL){
            traverse(root->left,A);
            traverse(root->right,A);
            A.emplace_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> A;
        traverse(root,A);
        return A;
    }
};
