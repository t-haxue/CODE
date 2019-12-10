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
    static int len(ListNode* p) {
        int s = 0;
        while (p) {
            ++s;
            p = p->next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = len(l1);
        int m = len(l2);
        if (n < m) swap(l1, l2);
        ListNode* ret = l1;
        while (l1) {
            if (l2) l1->val += l2->val;
            if (l2) l2 = l2->next;
            l1 = l1->next;
        }
        l1 = ret;
        int c = 0;
        while (l1) {
            l1->val += c;
            c = 0;
            if (l1->val >= 10) {
                c = l1->val / 10;
                l1->val %= 10;
            }
            if (l1->next == nullptr && c) {
                l1->next = new ListNode(c);
                c = 0; break;
            }
            l1 = l1->next;
        }
        return ret;
    }
};
