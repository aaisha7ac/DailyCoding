#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


void insertAtHead(Node* &head,int val) {

    Node* n = new Node(val);

    if(head == NULL) {
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;

}


void insertAtTail(Node* &head,int val) {

    if(head == NULL) {
        insertAtHead(head,val);
        return;
    }

    Node* n = new Node(val);
    
    Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}


void deleteAtHead(Node* &head) {

    // if (head == NULL)
    //     return;

    if(head->next == head) { // Only one node in the list
        delete head;
        head = NULL;
        return;
    }


    Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    Node* todelete = temp->next;

    temp->next = temp->next->next;
    head = head->next;

    delete todelete;

}

void deleteNode(Node* &head,int pos) {

    if(pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt != pos-1) { 
        temp = temp->next; 
        cnt++;
    }

    // after while loop temp will point to the node before the node to be deleted

    Node* todelete = temp->next;

    temp->next = temp->next->next;

    delete todelete;
}

void display(Node* &head) {

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);
    cout << endl;
}

int main() {

    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);

    int pos;
    cout << "Enter the position to be deleted: ";
    cin >> pos;
    
    deleteNode(head,pos); // it will handle if we want to delete middle node or last node
    display(head);

    return 0;


}