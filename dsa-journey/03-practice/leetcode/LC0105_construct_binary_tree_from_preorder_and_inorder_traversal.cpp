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
    TreeNode* helper(vector<int>& preorder,int pl,int pr,int il,int ir,unordered_map<int,int>& pos){
        if(pl>pr) return nullptr;
        TreeNode* root= new TreeNode(preorder[pl]);
        int idx=pos[root->val];
        int sz=idx-il;
        root->left=helper(preorder,pl+1,pl+sz,il,idx-1,pos);
        root->right=helper(preorder,pl+sz+1,pr,idx+1,ir,pos);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pos;
        for(int i=0;i<(int)inorder.size();i++) pos[inorder[i]]=i;
        return helper(preorder,0,(int)preorder.size()-1,0,(int)inorder.size()-1,pos);
    }
};
