#include <iostream>
using namespace std;
class LinkNode
{
	public: 
    int data;
	LinkNode *next;
	LinkNode(int data, LinkNode *first)
	{
		this->data = data;
		this->next = first;
	}
};
class CircularLinkedList
{
	public: 
    LinkNode *head;
	CircularLinkedList()
	{
		this->head = nullptr;
	}
	void insertEnd(int value);            
	void display();
	CircularLinkedList *splitLinkedList();
};
void CircularLinkedList::insertEnd(int value)
	{
                LinkNode *node=new LinkNode(value,NULL);
                LinkNode *temp;  
                if(node == NULL)
                    printf("\nOVERFLOW");
                else{
                    if(this->head == NULL){
                     this->head = node;    
                     node -> next = this->head;    
                        }
                    else{
                        temp = this->head;
                        while(temp->next != this->head)
                            temp = temp->next;
                            node->next = this->head;
                            temp -> next = node;
                            this->head = node;
                        }
                    }
    }
                
	void CircularLinkedList::display()
	{
        LinkNode *temp = this->head;
    if(this->head == NULL) return;
    do{
        cout<<temp->data<<' ';
        temp = temp->next;
    }while(temp != this->head);
	}


    // TC : O(n)
// SC : O(1)
CircularLinkedList* CircularLinkedList::splitLinkedList()
	{
	  // Write your code here
  CircularLinkedList* ans = new CircularLinkedList();
  // base case
  if(head==NULL) {
           return ans;
   }
  LinkNode* fast = head;
  LinkNode* slow = head;
  // Number of nodes given is even
  while(fast->next->next != head) {
      slow = slow->next;
      fast = fast->next->next;
  }
  LinkNode* head1 = head;
  LinkNode* head2 = slow->next;
  slow->next = head1;
  LinkNode* curr = head2;
  while(curr->next != head) {
	curr = curr->next;
  }
    curr->next = head2;
    ans->head = head2;
    return ans;
  }


  int main()
{
	
	int t;
    cin>>t;
    while(t--)
    {
        CircularLinkedList *cll1 = new CircularLinkedList();
        int n,data;
        cin>>n;
         while(n--){
            cin>>data;
            cll1->insertEnd(data);
         }
	CircularLinkedList *cll2 = cll1->splitLinkedList();
	cll1->display();
    cout<<endl;
	cll2->display();
    cout<<endl;
    }
	return 0;
}