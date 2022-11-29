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
    int count;
    
    pair<int,int> preorder(TreeNode*root){
        if(root==NULL){
            // cout<<"here"<<" ";
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            count++;
            return {root->val,1};
        }
        pair<int,int> a=preorder(root->left);
        pair<int,int> b=preorder(root->right);
        if((a.first+b.first+root->val)/(a.second+b.second+1)==root->val){
            // cout<<(a.first+b.first+root->val)/(a.second+b.second+1)<<" ";
            count++;
        }
        return {(a.first+b.first+root->val),(a.second+b.second+1)};
    }
public:
    Solution(){
        count=0;
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> a=preorder(root);
        return count;
    }
};