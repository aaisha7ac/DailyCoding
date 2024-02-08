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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* even_head = NULL;
        ListNode* odd_head = NULL;

        ListNode* even = NULL;
        ListNode* odd = NULL;

        ListNode* temp = head;

        int cnt = 1;

        while(temp != NULL) {

            if(cnt == 1) {
                odd_head = temp;
                odd = temp;
            }

            else if(cnt % 2 != 0) {
                odd->next = temp;
                odd = temp;
            }

            if(cnt == 2) {
                even_head = temp;
                even = temp;
            }

            else if(cnt % 2 == 0) {
                even->next = temp;
                even = temp;
            }

            temp = temp->next;
            cnt++;

        }

        odd->next = even_head;
        even->next = NULL;

        return odd_head;

    }
};