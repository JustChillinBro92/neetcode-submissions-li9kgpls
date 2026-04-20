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
private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = getMiddle(curr);

        ListNode* secondHalf = mid->next;
        mid->next = nullptr; // prevents cycle

        ListNode* rev = reverseList(secondHalf);

        while(rev) {
            ListNode* dest1 = curr->next;
            ListNode* dest2 = rev->next;

            curr->next = rev;
            rev->next = dest1;

            curr = dest1;
            rev = dest2;
        }
    }
};
