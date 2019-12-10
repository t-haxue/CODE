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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        while (head && head->val == val) head = head->next;
        ListNode* pre = head;
        ListNode* ret = head;
        while (head) {
            if (head->val == val) {
                pre->next = head->next;
                head = head->next;
            }
            else {
                pre = head;
                head = head->next;
            }
        }
        return ret;
    }
};
