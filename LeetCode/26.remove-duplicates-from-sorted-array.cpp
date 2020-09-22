/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //万事第一步,先判空
        if(nums.empty()) return 0;

        // //方法一: 利用迭代器实现原地删减
        // for(vector<int>::iterator iter = nums.begin(); iter != nums.end() - 1;){    //为什么这里要减1才对?不然最后的元素必定会遗失?
        // //因为在iter指向倒数第二个元素时,下面的if语句就已经判断完所有的元素了
        // //如果iter指向了最后一个元素,那么下面的if判断好像依旧生效,其结果就是最后一个元素也会被删除??
        // //具体原因不明
        //     if(*iter == *(iter + 1)){
        //         iter = nums.erase(iter);
        //     }
        //     else{
        //         ++iter;     //前增速度更快
        //     }
        // }
        //return nums.size();

        //方法二: 看了思路后.双指针法
        int front = 0, rear = 1;         
        while(rear < nums.size()){
            if(nums[front] == nums[rear]){
                ++rear;
            }
            else{
                nums[++front] = nums[rear++];
            }
        }
        return (front + 1);
    }
};
// @lc code=end

