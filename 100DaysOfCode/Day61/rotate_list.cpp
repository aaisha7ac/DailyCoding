class Solution {

    // TC : O(n) , n = length of the linked list
    // SC : O(1)

public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || k == 0) {
            return head;
        }

        ListNode* tempHead = head;
  
        ListNode* temp = head;
        ListNode* prev = NULL;
        int len = 0;

        // finding the last node and length of the linked list
        while(temp != NULL) {
            len++;
            prev = temp;
            temp = temp->next;
        }

        // cout << len << " " << prev->val << endl;

        int rotate = k % len;

        if(rotate == 0) {
            return head;
        }

        int cnt = len - rotate - 1; // -1 because temp is initialized with head
        temp = head;
        
        while(cnt--) {
            temp = temp->next;
        }

        // cout << temp->val;

        head = temp->next;
        temp->next = NULL;
        prev->next = tempHead;

        return head;
    }
};