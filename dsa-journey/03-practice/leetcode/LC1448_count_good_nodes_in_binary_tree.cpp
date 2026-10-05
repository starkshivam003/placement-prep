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
    void cnt(TreeNode* root,int& count,int h){
        if(root){
            if(root->val>=h){
                count++;
                h=root->val;
            }
            cnt(root->left,count,h);
            cnt(root->right,count,h);
        }
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int h=root->val;
        cnt(root,count,h);
        return count;
    }
};
