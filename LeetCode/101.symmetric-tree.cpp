/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
bool isMirror(TreeNode* node1, TreeNode* node2){
    if(node1 == NULL && node2 == NULL) return true;
    if(node1 != NULL && node2 == NULL || node1 == NULL && node2 != NULL) return false;
    if(node1->val != node2->val) return false;
    bool flag = true;
    flag &= isMirror(node1->left, node2->right);
    flag &= isMirror(node1->right, node2->left);
    return flag;
}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root, root);
    }
};
// @lc code=end

