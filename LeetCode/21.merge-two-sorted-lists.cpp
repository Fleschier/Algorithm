/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL && l2 == NULL)    return NULL;
        if(l1 == NULL && l2 != NULL)    return l2;
        if(l2 == NULL && l1 != NULL)    return l1;

        ListNode* new_head = l1->val <= l2->val ? l1 : l2; 
        if(new_head == l1){
            if(l1->next != NULL){
                 l1 = l1->next;
            }
            else{        //l1->next == NULL
                new_head->next = l2;
                return new_head;
            }
        } 
        else 
            if(l2->next != NULL){
                l2 = l2->next;
            }
           else{        //l2->next == NULL
                new_head->next = l1;
                return new_head;
            }

        ListNode* tmp = new_head;
        while(true){
            if(l1->val <= l2->val){
                tmp->next = l1;
                tmp = tmp->next;
                if(l1->next != NULL) l1 = l1->next;
                else {           //如果l1到头了,则将l2剩下的直接接上去
                    tmp->next = l2;
                    break;
                }
            }
            else{       //l1->val > l2->val
                tmp->next = l2;
                tmp = tmp->next;
                if(l2->next != NULL) l2 = l2->next;
                else{
                    tmp->next = l1;
                    break;
                }
            }
        }
        return new_head;
    }
};
// @lc code=end

