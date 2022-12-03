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
    int maxfreq=0;
    int preorder(TreeNode*root,map<int,int>&m){
        if(root==NULL){
            return 0;
        }
        int left=preorder(root->left,m);
        int right=preorder(root->right,m);
        m[left+right+root->val]+=1;
        maxfreq=max(maxfreq,m[left+right+root->val]);
        return left+right+root->val;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        preorder(root,m);
        int freq=0;
        vector<int>v;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==maxfreq){
                v.push_back(it->first);
            }
        }
        return v;
    }
};