/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* res = head;
        while(head->next != NULL){
            ListNode* tmp = head->next;
            while(head->val == tmp->val ){
                if(tmp->next == NULL) {
                    head->next = NULL;
                    return res;
                }
                tmp = tmp->next;
            }
            head->next = tmp;
            head = tmp;
        }
        return res;
    }
};
// @lc code=end

