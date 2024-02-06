#include <stdio.h>
#include <stdlib.h>
#include<iostream>
// A linked list node
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

class list{
    
    public:struct Node* head; 
    list(){ head = NULL; }
    //struct Node* getHead(){ return(head);}
};

struct Node* insertEnd(struct Node* head, int data)
{
    struct Node* node=new Node;
    // struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = head;
    node->data  = data;     //  Insert data in new node
    node->next = NULL;   // link new node to NULL as it is last node
    if (head == NULL)  // if list is empty add in beginning.
    {
        head = node;
        node->prev=NULL;
        return head;
    }
    while (last->next != NULL)  // Find the last node
        last = last->next;
    last->next = node;  // Add the node after the last node of list
    node->prev=last;
    return head;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        //printf("%d ", node->data);
        node = node->next;
    }
}

// TC : O(n)
// SC : O(1)
struct Node* rearrangeList(struct Node* head){
    //Write your code here 
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* temp = head;
    struct Node* even = NULL;
    struct Node* even_head = NULL;
    struct Node* odd = NULL;
    struct Node* odd_head = NULL;
    int i = 1;
    while(temp != NULL) {
    if(i == 2) {
        even = temp;
        even_head = temp;
    }
    else if(i % 2 == 0) {
        even->next = temp;
        temp->prev = even;
        even = temp;
    }
    if(i == 1) {
        odd = temp;
        odd_head = temp;
    }
    else if(i % 2 != 0) {
        odd->next = temp;
        temp->prev = odd;
        odd = temp;
    }
    i++;
    temp = temp->next;
  }
    even->next = odd_head;
    odd_head->prev = even;
    odd->next = NULL;
    even_head->prev = NULL;
    return even_head;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        list root,root1;
        int n, m;
        cin>>n;
        while(n--)
        {
        cin>>m;
        root.head = insertEnd(root.head, m);
        }
        root1.head = rearrangeList(root.head);
        printList(root1.head);
        cout<<"\n";
        
    }
    return 0;
}

