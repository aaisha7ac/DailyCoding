// TC : O(n)
// SC : O(1)

Node* rotateByK(Node* head, int k) {
  
  if(head == NULL || k == 0) {
    return head;
  }
  
  Node* temp = head;
  int len = 1;
  
  while(temp->next != NULL) {
    len++;
    temp = temp->next;
  }
  
  // k is greater than length of DLL
  if(k % len == 0) {
    return head;
  }
  
  temp->next = head;
  head->prev = temp;
  
 int cnt = 0;
  while(cnt < len - k) {
    cnt++;
    temp = temp->next;
  }
  
  head = temp->next;
  head->prev = NULL;
  temp->next = NULL;
  
  return head;
  
}