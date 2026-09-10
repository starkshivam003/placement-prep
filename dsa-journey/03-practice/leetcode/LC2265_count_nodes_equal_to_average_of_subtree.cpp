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
    pair<int,int> traverse(TreeNode* root, int& click){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> left=traverse(root->left,click);
        pair<int,int> right=traverse(root->right,click);
        int s=root->val+left.first+right.first;
        int n=1+right.second+left.second;

        if(s/n==root->val) click++;
        return {s,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int click=0;
        traverse(root,click);
        return click;
    }
};
