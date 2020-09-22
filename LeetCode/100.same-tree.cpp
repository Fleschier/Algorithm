/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
       if(p == NULL && q == NULL) return true;
       if(p == NULL && q != NULL || p != NULL && q == NULL) return false;
       if(p->val != q->val) return false;
       if(p->left == NULL && q->left != NULL || p->left != NULL && q->left == NULL) return false;
        if(p->right == NULL && q->right != NULL || p->right != NULL && q->right == NULL) return false;
       if(p->left != NULL && q->left != NULL) flag &= isSameTree(p->left, q->left);
       if(p->right != NULL && q-> right != NULL) flag &= isSameTree(p->right, q->right);
       return flag;
    }
};
// @lc code=end

