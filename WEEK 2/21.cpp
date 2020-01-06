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
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode* ans = l1;
        while (l2) {
            while (l1->next && l2->val > l1->next->val) l1 = l1->next;
            ListNode* tmp = l2;
            l2 = l2->next;
            tmp->next = l1->next;
            l1->next = tmp;
        }
        return ans;
    }
};
