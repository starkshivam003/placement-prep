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
    const int INF=1001;
    array<int,3> f(TreeNode* r){
        if(!r) return {INF,0,INF};
        auto [la,lb,lc]=f(r->left);
        auto [ra,rb,rc]=f(r->right);
        int A=1+min({la,lb,lc})+min({ra,rb,rc});
        int B=min(la+min(ra,rb),ra+min(la,lb));
        int C=lb+rb;
        return {A,B,C};
    }
    int minCameraCover(TreeNode* root) {
        auto [a,b,c]=f(root);
        return min(a,b);
    }
};
