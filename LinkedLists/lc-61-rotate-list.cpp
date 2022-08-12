/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        int length = 1;
        ListNode* temp = head;
        while(temp->next)
        {
            length++;
            temp = temp->next;
        }

        temp->next = head;

        k %= length;

        for(int i = 0; i < length-k; i++)
        {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};
// @lc code=end

