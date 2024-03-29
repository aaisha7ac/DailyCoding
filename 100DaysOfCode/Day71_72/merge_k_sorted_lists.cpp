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

    // TC : O(n)
    // SC : O(1)
    
public:

    ListNode* merge(ListNode* l1,ListNode* l2) {

        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }

        if(l1 == NULL) {
            return l2;
        }

        if(l2 == NULL) {
            return l1;
        }

        if(l2->val < l1->val) {
            swap(l1,l2);
        }

        ListNode* head = l1;

        while(l1 != NULL && l2 != NULL) {
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }

        return head;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if(n == 0) {
            return NULL;
        }

        ListNode* l1 = lists[0];

        for(int i = 1; i < n; i++) {
            l1 = merge(l1,lists[i]);
        }
        
        return l1;

    }
};