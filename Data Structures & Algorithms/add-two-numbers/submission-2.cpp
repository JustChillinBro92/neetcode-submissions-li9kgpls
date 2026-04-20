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
        string s1, s2;
        while(l1 || l2) {
            if(l1) {
                s1 = to_string(l1->val) + s1;
                l1 = l1->next;    
            }
            if(l2) {
                s2 = to_string(l2->val) + s2;
                l2 = l2->next;
            }
        }

        int sum = stoi(s1) + stoi(s2);
        // cout << sum;
        ListNode* l3 = new ListNode(0);
        ListNode* curr = l3;

        while(sum > 0) {
            curr->next = new ListNode(sum % 10);
            sum /= 10;
            curr = curr->next;
        }
        return l3->next ? l3->next : new ListNode(0);
    }
};
