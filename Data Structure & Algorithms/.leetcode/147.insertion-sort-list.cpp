/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head)
    {
        auto cursor = head;
        ListNode dummy(0);
        while (cursor)
        {
            auto pre = &dummy;
            auto next = cursor->next;
            while (pre->next && pre->next->val < cursor->val)
                pre = pre->next;
            cursor->next = pre->next;
            pre->next = cursor;
            cursor = next;
        }
        return dummy.next;
    }
};
// @lc code=end

