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
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(0);
        ListNode* curr = list3;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if(list1 == nullptr) curr->next = list2;
        else curr->next = list1;

        return list3->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(lists.empty()) return {};

        int interval = 1;
        while(interval < size) {
            for(int i = 0; i + interval < size; i+= interval*2) {
                lists[i] = mergeList(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};
