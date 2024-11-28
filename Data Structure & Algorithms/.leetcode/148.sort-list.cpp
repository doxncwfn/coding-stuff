/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* cursor = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cursor->next = l1;
                l1 = l1->next;
            }
            else
            {
                cursor->next = l2;
                l2 = l2->next;
            }
            cursor = cursor->next;
        }
        cursor->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
// @lc code=end

