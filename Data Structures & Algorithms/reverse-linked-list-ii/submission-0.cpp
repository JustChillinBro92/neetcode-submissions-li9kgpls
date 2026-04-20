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
    ListNode* reverseList(ListNode* p, ListNode* head, ListNode* tail) {
        ListNode* curr = head;
        ListNode* prev = p;
        ListNode* stop = tail->next;

        while(curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* lb_node;
        ListNode* ub_node;

        int count = 1;
        while(count <= right) {
            if(count == left - 1) prev = curr;
            if(count == left) lb_node = curr;
            if(count == right) ub_node = curr; 

            curr = curr->next;
            count++;
        }

        ListNode* ub_next = ub_node->next;
        ListNode* rev = reverseList(prev, lb_node, ub_node);
        
        // connect 1st part
        if(prev) prev->next = rev;
        else head = rev;
        // connect 2nd part
        lb_node->next = ub_next;
        
        return head;
    }
};