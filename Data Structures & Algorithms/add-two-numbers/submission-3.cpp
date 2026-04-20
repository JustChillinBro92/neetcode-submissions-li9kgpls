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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* add_list = new ListNode(0);
        ListNode* curr = add_list;
        int carry = 0;

        while(l1 || l2 || carry) {
            int column_sum = carry;

            if(l1) {
                column_sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                column_sum += l2->val;
                l2 = l2->next;
            }

            carry = column_sum / 10;
            curr->next = new ListNode(column_sum % 10);
            curr = curr->next;
        }
        return add_list->next;
    }
};
