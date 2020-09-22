/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        
        //可能存在正负,不能这样提前判断
        // if(root->val > sum && root->val >= 0) return false;
        // if(root-val < sum && root->val < 0)

        //此方法会修改树中结点的值
        if(root->left != NULL) root->left->val += root->val;
        if(root->right != NULL) root->right->val += root->val;
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum) return true;
            else return false;
        }
        return (hasPathSum(root->left,sum) | hasPathSum(root->right, sum));
        
    }
};
// @lc code=end

