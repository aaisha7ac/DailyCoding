#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize Node with a value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class ListCircularCheck {
public:
    Node* _last = NULL;

    void printList(Node* head);
    Node* insertEnd(Node* head, int data);
    int isCircular(Node* head);
};

void ListCircularCheck::printList(Node* head) {
    Node* t = head;
    if (head == NULL) return;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
}

Node* ListCircularCheck::insertEnd(Node* head, int data) {
    Node* node = new Node(data); // Using Node constructor to initialize node with data
    if (head != NULL) {
        _last->next = node;
    } else {
        head = node;
    }
    _last = node;
    _last->next = head; // Making the last node point to head for circular list
    return head;
}


/*
class Node {
public:
    int data;
    Node* next;
    // Constructor to initialize Node with a value
    Node(int value) {
        data = value;
        next = NULL;
    }
};
class ListCircularCheck {
public:
    Node* _last = NULL;
    void printList(Node* head);
    Node* insertEnd(Node* head, int data);
    int isCircular(Node* head);
};
*/
// TC : O(n)
// SC : O(1)
int ListCircularCheck::isCircular(Node* head) {
    // Write your code here
  if(head == NULL) {
    return 1;
  }
  Node* fast = head;
  Node* slow = head;
  while(fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow) {
      if(slow == head) {
        return 1;
      }
      else {
        return 0;
      }
    }
  }
  return 0;
}

int main() 
{
    int t;
    ListCircularCheck lc;
    cin >> t;
    while (t--) {
        lc._last = NULL;
        Node* head = NULL;
        int n, m;
        cin >> n;
        while (n--) {
            cin >> m;
            head = lc.insertEnd(head, m);
        }
      int x;
    cin>>x;
    if (x == -1 && lc._last != NULL)
      lc._last->next = NULL;
    else if (head) {
       Node* curr = head;
      while (curr && x--)
        curr = curr->next;
      lc._last->next = curr;
    }
        // Your remaining code for setting up the linked list and checking circularity
        cout << lc.isCircular(head) << endl;
    }
    return 0;
}

