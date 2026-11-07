/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void ser(TreeNode* root,string& data){
        if(!root) {
            data+="N";
            data+=",";
            return;
        }
        data+=to_string(root->val);
        data+=",";
        ser(root->left,data);
        ser(root->right,data);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        ser(root,data);
        return data;
    }

    TreeNode* deser(vector<string>& t,int& i){
        const string& x=t[i++];
        if(x=="N") return nullptr;
        TreeNode* n=new TreeNode(stoi(x));
        n->left=deser(t,i);
        n->right=deser(t,i);
        return n;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> t;
        stringstream ss(data);
        string s;
        while(getline(ss,s,',')) t.push_back(s);
        int i=0;
        return deser(t,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
