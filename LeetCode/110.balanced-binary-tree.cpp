/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // calculate the depth of current node's sub-tree
    int depth(TreeNode* node){
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return 1;
        int left_depth = depth(node->left);
        int right_depth = depth(node->right);
        return left_depth > right_depth ? ++left_depth : ++right_depth;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        // // top to bottom     (not recommended)
        // int left_depth = depth(root->left);
        // int right_depth = depth(root->right);
        // if(left_depth - right_depth > 1 || right_depth - left_depth > 1 ) return false;
        // return (isBalanced(root->left) & isBalanced(root->right));

        // bottom to top (best way)
        if(isBalanced(root->left) && isBalanced(root->right)){
            int left_depth = depth(root->left);
            int right_depth = depth(root->right);
            if(left_depth - right_depth > 1 || right_depth - left_depth > 1 ) return false;
            return true;
        }
        return false;
    }
};
// @lc code=end