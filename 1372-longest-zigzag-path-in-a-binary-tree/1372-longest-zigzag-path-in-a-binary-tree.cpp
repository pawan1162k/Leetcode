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
    int preorder(TreeNode*root,int count,char dir){
        if(root==NULL){
            return count;
        }
        int a=preorder(root->left,dir=='r'?count+1:0,'l');
        int b=preorder(root->right,dir=='l'?count+1:0,'r');
        return max(a,b);
    }
public:
    int longestZigZag(TreeNode* root) {
        int a=preorder(root->left,0,'l');
        int b=preorder(root->right,0,'r');
        return max(a,b);
    }
};