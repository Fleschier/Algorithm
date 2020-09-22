/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if(left_depth == 0) return ++right_depth;   //如果有个子树的高度为0,则说明此子树缺失,故不存在叶子结点
        if(right_depth == 0) return ++left_depth;
        return left_depth > right_depth ? ++right_depth : ++left_depth;
    }
};
// @lc code=end

