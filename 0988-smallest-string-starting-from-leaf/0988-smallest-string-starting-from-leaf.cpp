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
    set<string>st;
    void preorder(TreeNode*root,string s){
        if(root==NULL){
            return ;
        }
        s= char('a'+root->val)+s;
        if(root->left==NULL && root->right==NULL){
            st.insert(s);
            return;
        }
        preorder(root->left,s);
        preorder(root->right,s);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            string s="";
            s+=char('a'+root->val);
            return s;
        }
        preorder(root,"");
        for(auto it=st.begin();it!=st.end();it++){
            if((*it).length()>1){
                return *it;
            }
        }
        return "";
    }
};