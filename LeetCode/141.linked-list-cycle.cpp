/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        while(true){
            if(head->next == NULL) return false;
            if(head->val == -999) break;            //非常无赖的解法
            if(head->val != -999)  head->val = -999;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

// 还有一种快慢指针的解法