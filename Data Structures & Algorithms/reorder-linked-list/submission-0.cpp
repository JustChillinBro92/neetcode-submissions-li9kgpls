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
        ListNode* Next;

        while(curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // 1. find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse 2nd half & split 1st half
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;

        // 3. merge 1st & 2nd half
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
