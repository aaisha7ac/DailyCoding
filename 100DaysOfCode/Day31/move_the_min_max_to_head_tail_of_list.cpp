/* 
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    void  forwardPrint();
    void  insertEnd(int data);
     void  shiftSmallLarge();
};
 */

// TC : O(n)
// SC : O(1)

// to find previous node of min
Node* getprevMin(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    Node* mn = head;
    while(temp->next != NULL) {
        if(temp->next->data < mn->data) {
        mn = temp->next;
        prev = temp;
        }
        temp = temp->next;
    }
    return prev;
}

// to find previous node of max
Node* getprevMax(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    Node* max = head;
    while(temp->next != NULL) {
        if(temp->next->data > max->data) {
        max = temp->next;
        prev = temp;
        }
        temp = temp->next;
    }
    return prev;
}

void LinkedList:: shiftSmallLarge() {
    if(head == NULL || head->next == NULL) {
        return;
    }
    // previous node before the min value
    Node* prev_min = getprevMin(head);
    // if min value is already at head then prev_min == NULL
    if(prev_min != NULL) {
        Node* mn = prev_min->next;
        prev_min->next = mn->next;
        mn->next = head;
        head = mn;
    }
    // previous node before the max value
    Node* prev_max = getprevMax(head);
    // if prev_max == NULL that means max is already at the tail
    if(prev_max != NULL) {
        Node* max = prev_max->next;
        prev_max->next = max->next;
        Node* temp = head;
        while(temp->next != NULL) {
        temp = temp->next;
        }
        max->next = NULL;
        temp->next = max;
    }
}