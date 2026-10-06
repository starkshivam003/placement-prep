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
    void helper(TreeNode* root, const int& targetSum,long long sum,unordered_map<long long,int>& seen, int& ans){
        if(root){
            sum+=root->val;
            if(seen.count(sum-targetSum)) ans+=seen[sum-targetSum];
            seen[sum]++;
            helper(root->left,targetSum,sum,seen,ans);
            helper(root->right,targetSum,sum,seen,ans);
            seen[sum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> seen;
        int ans=0;
        seen[0]=1;
        helper(root,targetSum,0,seen,ans);
        return ans;
    }
};
