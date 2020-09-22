/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> one_line;       //一行所有的值
        vector<TreeNode*> nodes;  //结点
        //vector<TreeNode*> tmp;  //临时
        nodes.push_back(root);
        int begin = 0, end = 0;
        int count = 0;
        while(true){
            for(int i = begin; i <= end; i++){
                if(nodes[i] != NULL){
                    count += 2;
                    one_line.push_back(nodes[i]->val);
                    nodes.push_back(nodes[i]->left);      
                    nodes.push_back(nodes[i]->right);
                }
            }
            begin = end + 1;
            end += count;
            count = 0;
            if(one_line.empty()) break;
            res.push_back(one_line);
            one_line.clear();
            // nodes = tmp;    //赋值操作符即为深拷贝
            // tmp.clear();
        }
        // vector<vector<int>> result;          //问题出在这里,提示内存错误***********
        // int len = res.size();
        // result.reserve(len);
        // for(int i = len - 1;  i >= 0; i--){
        //     result[len - i - 1] = res[i];
        // }
        // return result;
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

