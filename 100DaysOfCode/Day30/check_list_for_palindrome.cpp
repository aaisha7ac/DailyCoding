#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class List{
    Node *head;
    Node *_last;
    public:
    List(){
        head=NULL;
        _last = NULL;
    }
    void forwardPrint(Node*);
    void insertEnd(int);
    int checkPalindrome() ;
};

void List::forwardPrint(Node* head)
{
    if (head == NULL)
        return;

    cout<<head->data<<" ";
    forwardPrint(head->next);
}



void List::insertEnd(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data  = data;     //  Insert data in new node
    node->next = NULL;   // link new node to NULL as it is last node
    if (head == NULL)  // if list is empty add in beginning.
    {
            head = node;
            _last = node;
        return;
    }
    _last->next = node;  // Add the node after the last node of list
    _last = node;
    return;
}

// TC : O(n)
// SC : O(1)
Node* reverse(Node* head) {
  Node* curr = head;
  Node* prev = nullptr;
  while(curr != nullptr) {
	Node* front = curr->next;
    curr->next = prev;
    prev = curr;
    curr = front;
  }
  return prev;
}
int List::checkPalindrome() {
    // Write your code here
    if(head == NULL) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* first = head;
    Node* second = reverse(slow->next);
    while(second != NULL) {
        if(first->data != second->data) {
        return 0;
        }
        first = first->next;
        second = second->next;
    }
    return 1;
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        List ll;
        int ans;
        cin>>n;
        while(n--)
        {
        cin>>m;
        ll.insertEnd(m);
        }
        ans = ll.checkPalindrome();
        cout<<ans<<endl;
    }
    return 0;
}