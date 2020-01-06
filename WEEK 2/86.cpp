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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* tmp = nullptr;
        ListNode* ret = nullptr;
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                ListNode* nx = new ListNode(p->val);
                if (tmp == nullptr) {
                    tmp = nx;
                    ret = tmp;
                }
                else {
                    tmp->next = nx;
                    tmp = nx;
                }
            }
            p = p->next;
        }
        p = head;
        while (p) {
            if (p->val >= x) {
                ListNode* nx = new ListNode(p->val);
                if (tmp == nullptr) {
                    tmp = nx;
                    ret = tmp;
                }
                else {
                    tmp->next = nx;
                    tmp = nx;
                }
            }
            p = p->next;
        }
        return ret;
    }
};
