/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;

        int front = 0, rear = nums.size() - 1;

        if(front == rear){      //处理长度为1的情况
            if(nums[0] == val) return 0;
            else return 1;
        }

        while( front <= rear){
            while(nums[rear] == val && rear >= 1) rear--;
            if(nums[front] == val){
                if(front >= rear){      //special condition [1,1,1...,1]  1     [2,2,3] 2
                    return front;
                }
                nums[front++] = nums[rear--];
            }
            else ++front;
        }
        if(front > rear) return front;
        return (front + 1);
    }
};
// @lc code=end

