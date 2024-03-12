#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {

    Node *head;
    public:
    LinkedList() {
        head = nullptr;
    }
  Node* getHead(){return head;}
  void setHead(Node *r){ head=r;}
  
  void insert(int data);
};
    
    void LinkedList:: insert(int data) {
        Node *newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


#include <bits/stdc++.h>
Node* mergeLinkedLists(LinkedList list1, LinkedList list2){
        Node* head1 = list1.getHead();
        Node* head2 = list2.getHead();
        if(head1 == nullptr) {
            while(head2 != NULL) {
                cout << head2->data << " ";
                head2 = head2->next;
            }
			return head2;
        }
        if(head2 == nullptr) {
            while(head1 != NULL) {
                cout << head1->data << " ";
                head1 = head1->next;
            }
            return head1;
        }
       if(head2->data < head1->data) swap(head1,head2);
        Node* head = head1;
        while(head1 != NULL && head2 != NULL) {
            Node* temp = NULL;
            while(head1 != NULL && head1->data < head2->data) {
                temp = head1;
                head1 = head1->next;
            }
            temp->next = head2;
            swap(head1,head2);
        }
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
        return head;
}


int main() {
    int n, m;
    cin >> n;
    
    LinkedList list1;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list1.insert(data);
    }
    
    cin >> m;
    
    LinkedList list2;
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        list2.insert(data);
    }
    
    LinkedList mergedList;
    mergedList.setHead(mergeLinkedLists(list1, list2));
    
    return 0;
}


    
    
        