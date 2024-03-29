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

    ListNode* reverse(ListNode* head) {


        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;

        while(curr != NULL) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
    

    void reorderList(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Find the middle node
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the half linked list
        ListNode* p2 = reverse(slow->next);

        ListNode* p1 = head;
        head = p1;
        
        slow->next = NULL;

        ListNode* p1front = NULL;
        ListNode* p2front = NULL;
        
        while(p1 != NULL && p2 != NULL) {
            
            p1front = p1->next;
            p2front = p2->next;

            p1->next = p2;
            p2->next = p1front;

            p1 = p1front;
            p2 = p2front;
        }

    }
};