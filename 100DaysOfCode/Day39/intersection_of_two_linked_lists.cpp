/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

    // TC : O(m + n)
    // SC : O(1)

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(temp1 == temp2) {
            return temp1;
        }

        while(temp1 != temp2) {

            if(temp1 == NULL) {
                temp1 = headB;
            }
            else {
                temp1 = temp1->next;
            }


            if(temp2 == NULL) {
                temp2 = headA;
            }
            else {
                temp2 = temp2->next;
            }

            if(temp1 == temp2) {
                return temp1;
            }
        }

        return NULL;
    }
};