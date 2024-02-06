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

// TC : O(max(m,n)) , m = length of l1 , n = l2
// SC : O(size of addition of two list)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head;
 
        int carry = 0;
        vector<int>result;

        while(l1 != NULL || l2 != NULL) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            result.push_back(sum % 10);
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        if(carry > 0) {
            result.push_back(carry);
        }

        ListNode* prev = new ListNode(result[0]);
        head = prev;

        for(int i = 1; i <  result.size(); i++) {
            ListNode* newNode = new ListNode(result[i]);
            prev->next = newNode;
            prev = newNode;
        }

        return head;
    }
};