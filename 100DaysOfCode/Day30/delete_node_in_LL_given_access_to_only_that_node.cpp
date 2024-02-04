#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data){
    this->data=data;
    next=NULL;
    }
};

class LinkedList{
    Node* head;
    public:
      LinkedList(){
        head=NULL;
      }
    Node* getHead();
    void forwardPrint();
    void insertEnd(int);
    void deleteNode(Node*); 
};

Node* LinkedList::getHead(){
  return head;
}
void LinkedList::forwardPrint()
{
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}

void LinkedList::insertEnd(int data){
  Node* node = new Node(data);
  Node* last = head;
  if(head == NULL)  // if list is empty add in beginning.
  {
    head = node;
    return;
  }
  while(last->next != NULL)  // Find the last node
    last = last->next;
  last->next = node;  // Add the node after the last node of list
  return;
}

void LinkedList::deleteNode(Node* node) {
  // Handle case when the node or the list is empty
    if (node == nullptr || head == nullptr) {
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    // If the node to be deleted is the head
    if (temp == node) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr) {
      // node to be deleted should not be the last node
        if (temp == node && temp->next != nullptr) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
  // it will handle the case if node to be deleted is not found
   	if(temp == nullptr) {
      return;
    }
	else {
      prev->next = prev->next->next;
      delete temp;
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    LinkedList l;
    Node *t1, *t2, *t3;
    int n,m,k;
    cin>>n;
    while(n--)
    {
      cin>>m;
      l.insertEnd(m);
    }
    cin>>k;
    t1=l.getHead();
    if(k>0){
      while(k--) t1 = t1->next;
    }
    l.deleteNode(t1);
    l.forwardPrint();
    cout<<endl;
  }
  return 0;
}