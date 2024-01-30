#include<iostream>
#include<cstdio>

using namespace std;
class CQStack
{
  public:
  int maxSize; // size of stack array
  int stackArray[100];
  int top; // top of stack
  CQStack();
  void push(int j);
  int pop();
  bool isEmpty();
  bool isFull();
};

CQStack::CQStack() // constructor
  {
    maxSize=100;
    top = -1; // no items yet
  }
  void CQStack::push(int j) // put item on top of stack
  {
    if(isFull())
      return;
    else
    {
      top++;
      stackArray[top] = j; // increment top, insert item
    }
  }
  int CQStack::pop() // take item from top of stack
  {
    if (isEmpty())
      return -1;
    else
    {
      int temp=stackArray[top--];
      return temp; // access item, decrement top
    }
  }
  bool CQStack::isEmpty() // true if stack is empty
  {
    return (top == -1);
  }
  bool CQStack::isFull() // true if stack is full
  {
    return (top == maxSize-1);
  }


  /*class CQStack
{
  public:
  int maxSize; // size of stack array
  int stackArray[100];
  int top; // top of stack
  CQStack();
  void push(int j);
  int pop();
  bool isEmpty();
  bool isFull();
};
push(int), pop(), isEmpty(), isFull() are available on the given Stack. */
void enqueue(CQStack *st1, CQStack *st2, int item) {
	st1->push(item);
}
int dequeue(CQStack *st1, CQStack *st2) {
	if(st1->isEmpty()) {
    	return -1;
  	}
  	while(!st1->isEmpty()) {
       st2->push(st1->pop());
   	}
    int val = st2->pop();
    while(!st2->isEmpty()) {
        st1->push(st2->pop());
    }
    return val;
}

int main()
{
  int t, n, q1, q2, k;
  cin>>t;
  
  CQStack st1;
  CQStack st2;
  while(t>0)
  {
    cin>>q1;
    if(q1 == 1)
    {
      cin>>q2;
      enqueue(&st1, &st2, q2);
    }
    else
      cout<<dequeue(&st1, &st2)<<" ";
    t--;
  }
  cout<<endl;
  return 0;
}