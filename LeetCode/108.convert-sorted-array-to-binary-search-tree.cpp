/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    void generate_tree(int begin, int end, vector<int>& nums , bool flg, TreeNode* father){
        if(begin == end && flg){
            // TreeNode left = TreeNode(nums[begin]);       //要生成永久对象这样是不对的,这样是在栈中生成,栈由系统控制
            // father->left = &left;
            //如果要生成可以返回的对象,要在堆中生成,用new关键字
            //堆由程序控制,故用完之后要用delete删除,防止内存泄露
            father->left = new TreeNode(nums[begin]);
            return;
        }
        if(begin == end && !flg){
            // TreeNode right = TreeNode(nums[begin]);
            // father->right = &right;
            father->right = new TreeNode(nums[begin]);
            return;
        }
        int idx = (begin + end) / 2;
        TreeNode* tmp = new TreeNode(nums[idx]);
        if(idx - 1 >= begin)
            generate_tree(begin, idx - 1, nums, true, tmp);
        if(idx + 1 <= end)
            generate_tree(idx + 1, end, nums, false, tmp);
        if(flg){    //flg = true, 左子树.
            father->left = tmp;
        }
        if(!flg){
            father->right = tmp;
        }
    }
    //[1,2,3,4] begin = 0, end = 3.   idx = 1; => left(0, 0) right(2,3) => idx = 2; => right(3,3)
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;

        int mid = (nums.size() - 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(mid - 1 >= 0)
            generate_tree(0, mid - 1, nums, true, root);
        if(mid + 1 <= nums.size() - 1)
            generate_tree(mid + 1, nums.size() - 1, nums, false, root);

        return root;
    }
};
// @lc code=end

