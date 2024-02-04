#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val){
        data  = val; 
        next = NULL; 
    }
};

class LinkedList{
  Node* head,*_last;
 public:
    LinkedList(){
        head=NULL;
        _last = NULL;
    }
    void forwardPrint();
    void insertEnd(int data);
    Node* getHead() {
        return head;
    }
    void setHead(Node* n){
        head=n;
    }
    void loop(int);
};

void LinkedList::forwardPrint()
{
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void LinkedList::insertEnd(int data)
{
    Node* node = new Node(data);
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
void LinkedList::loop(int x){
    if (x == -1 && _last != NULL)
        _last->next = NULL;
        else if (head) {
        Node* curr = head;
        while (curr && x--)
            curr = curr->next;
        _last->next = curr;
    }
}


/* 
* class Node
* {
* public:
*  int data;
*  Node* next;
* }
* The above class defines the linked list node.
* class LinkedList{
* public:
*  void forwardPrint(Node* head);
*  void insertEnd(Node** head, int data);
*  int loopInList(Node* head); 
*};
 *
 *  The above class defines the linked list.
 */
// TC : O(n)
// SC : O(1)
int loopInList(Node* head) {
  // Write your code here
    if(head == nullptr || head->next == nullptr) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    int check = 0;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        // loop exits and finding the starting point of linked list
        if(slow == fast) {
        check = 1;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        break;
        }
    }
    if(check == 0) {
        return 0;
    }
    Node* temp = slow->next;
    int cnt = 0;
    while(temp != slow) {
        cnt++;
        temp = temp->next;
    }
    cnt++;
    return cnt;
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        int ans;
        cin>>n;
        LinkedList l1;
        while(n--){
        cin>>m;
        l1.insertEnd(m);
        }
        int x;
        cin >> x;
        l1.loop(x);
        ans = loopInList(l1.getHead());
        cout<<ans<<endl;
    }
    return 0;
}
