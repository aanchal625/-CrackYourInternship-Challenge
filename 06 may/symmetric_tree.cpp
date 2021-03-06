// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool helper(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2){return true;}
        if(root1 && root2 && root1->val==root2->val){
            return helper(root1->left,root2->right) && helper(root1->right,root2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};