#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with given data
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    // Function to print the linked list in forward order
    void forwardPrint() ;
    void reverseList();
    // Function to insert a new node at the end of the linked list
    void insertEnd(int); 
 
};
void LinkedList::forwardPrint() {
    if (head == nullptr)
        return;
    else
    {
        Node* temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    }     
}

void LinkedList::insertEnd(int data) {
    Node* node = new Node(data);
    Node* last = head;

    if (head == nullptr) {
        head = node;
        return;
    }

    while (last->next != nullptr)
        last = last->next;
        last->next = node;
}

/*class Node {
public:
    int data;
    Node* next;
    // Constructor to initialize a node with given data
    Node(int val) : data(val), next(nullptr) {}
};*/
// Return the new head of reversed list

void LinkedList::reverseList() {
    // Write your code here
    if(head == nullptr) {
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;
    while(curr != nullptr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    while(prev->next != nullptr) {
        cout << prev->data << " ";
        prev = prev->next;
    }
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        LinkedList linkedList;
        cin >> n;
        while (n--) {
            cin >> m;
            linkedList.insertEnd(m);
        }

       linkedList.reverseList();
        linkedList.forwardPrint();
        cout << endl;
    }
    return 0;
}
