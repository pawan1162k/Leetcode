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
    string preorder(TreeNode*root,string s){
        if(root==NULL){
            return "~";
        }
        s= char('a'+root->val)+s;
        if(root->left==NULL && root->right==NULL){
            return s;
        }
        string a=preorder(root->left,s);
        string b=preorder(root->right,s);
        if(a!="~" && b!="~"){
            return a<b?a:b;
        }
        else if(a=="~" && b!="~"){
            return b;
        }
        return a;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            string s="";
            s+=char('a'+root->val);
            return s;
        }
        return preorder(root,"");
        // for(auto it=st.begin();it!=st.end();it++){
        //     if((*it).length()>1){
        //         return *it;
        //     }
        // }
        // return "";
    }
};