#include<iostream>
using namespace std;

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
    void LinkedList:: forwardPrint() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void LinkedList:: insertEnd(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = node;
    }

    #include<bits/stdc++.h>
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
// SC : O(n)
void LinkedList:: shiftSmallLarge() {
  // Write your code here
    if(head == NULL || head->next == NULL) {
        return;
    }
    int max = INT_MIN;
    int min = INT_MAX;
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data > max) {
        max = temp->data;
        }
        if(temp->data < min) {
        min = temp->data;
        }
        temp = temp->next;
    } 
    temp = head;
    vector<int>v;
    while(temp != NULL) {
        if(temp->data != max && temp->data != min) {
        v.push_back(temp->data);
        }
        temp = temp->next;
    }
    temp = head;
    temp->data = min;
    temp = temp->next;
    int i = 0;
    while(temp->next != NULL) {
        temp->data = v[i];
        i++;
        temp = temp->next;
    }
    temp->data = max;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        LinkedList list;
        cin >> n;
        while (n--) {
            cin >> m;
            list.insertEnd(m);
        }
        list.shiftSmallLarge();
        list.forwardPrint();
        cout << endl;
    }
    return 0;
}






