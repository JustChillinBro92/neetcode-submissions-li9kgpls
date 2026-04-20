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
        int length = 0, del_index;

        while(curr) {
            length++;
            curr = curr->next;
        }
        del_index = length - n;

        ListNode* toDel;
        if(del_index == 0) {
            toDel = head;
            head = head->next;
            delete toDel;
            return head;
        }

        curr = head;
        for(int i = 1; i < del_index; i++) curr = curr->next;

        toDel = curr->next;
        curr->next = toDel->next;

        delete toDel;
        return head;
    }
};
