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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;
        while(l1 && l2) {
            l1->val += (l2->val + carry);
            if(l1->val >= 10) {
                carry = 1;
                l1->val -= 10;
            }
            else {
                carry = 0;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1) prev->next = l2;
        l1 = prev->next;
        while(l1) {
            l1->val += carry;
            if(l1->val >= 10) {
                carry = 1;
                l1->val -= 10;
            }
            else {
                carry = 0;
            }
            prev = l1;
            l1 = l1->next;
        }
        if(carry == 1) {
            ListNode *end = new ListNode(carry);
            prev->next = end;
        }
        return head;
    }
};