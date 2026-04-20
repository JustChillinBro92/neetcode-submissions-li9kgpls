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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 0;
        while(curr) {
            length++;
            curr = curr->next;
        }
        curr = head;

        // stupid fucking edge case
        ListNode* toDel;
        if(n == length) {
            toDel = head;
            head = head->next;
            delete toDel;
            return head;
        }

        int n_count = 0;
        while(curr) {
            n_count++;
            if(n_count == (length - n)) {
                toDel = curr->next;
                curr->next = toDel->next;
                delete toDel;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
