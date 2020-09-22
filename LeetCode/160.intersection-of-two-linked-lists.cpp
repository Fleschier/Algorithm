/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    // 双指针法:错的人迟早会走散，而对的人迟早会相逢！
    // 函数返回值: 相交的起始结点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* A = headA;
        ListNode* B = headB;
        ListNode* rearA ,* rearB;   //分别记录A和B的末尾结点,若相交则末尾必须相同
        while(true){
            bool flg_A = false, flg_B = false;
            if(rearA != NULL && rearB != NULL && rearA->val != rearB->val) return false;
            if(A->next == NULL && !flg_A){
                rearA = A;
                A = headB;
                flg_A = true;
            }
            if(B->next == NULL && !flg_B){
                rearB = B;
                B = headA;
                flg_B = true;
            }
            if(flg_A && flg_B && A->val == B->val) return A;        //找到交点
            if(flg_A && flg_B && A->next == NULL && B->next == NULL) return NULL;   //未找到交点
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
};
// @lc code=end

