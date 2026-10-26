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
    void f(TreeNode* root,vector<string>& ans,vector<int>& path){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left&&!root->right){
            string s=to_string(path[0]);
            for(int i=1;i<(int)path.size();i++){
                s+="->"+to_string(path[i]);
            }
            ans.push_back(s);
        }
        else{
            f(root->left,ans,path);
            f(root->right,ans,path);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        f(root,ans,path);
        return ans;
    }
};
