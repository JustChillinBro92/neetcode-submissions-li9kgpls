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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split at middle and reverse 2nd half
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;

        // merge both half
        ListNode* first = head;

        while(first && second) {
            ListNode* first_dest = first->next;
            ListNode* second_dest = second->next;

            first->next = second;
            second->next = first_dest;

            first = first_dest;
            second = second_dest;
        } 
    }
};
