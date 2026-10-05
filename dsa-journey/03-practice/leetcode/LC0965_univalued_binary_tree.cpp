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
    void uni(TreeNode* root,int& x,bool& yes){
        if(!root) return;
        if(root->val!=x){
            yes=false;
            return;
        }
        uni(root->left,x,yes);
        uni(root->right,x,yes);
    }
    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        bool yes=true;
        uni(root,x,yes);
        return yes==true;
    }
};
