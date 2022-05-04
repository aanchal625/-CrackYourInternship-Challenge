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
    int mx=0;
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=helper(root->left);
        int rh=helper(root->right);
        mx=max(mx,lh+rh);
        return 1+max(lh,rh);
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        helper(root);
        return mx;
        
        
        
        
    }
};