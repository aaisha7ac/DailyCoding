#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class QueueArray
{
  public:
  int SIZE;
  int front;
  int rear;
  int array[100];
  QueueArray()
  {
    SIZE=100;front=-1;rear=-1;
  }

  // Method to add an item to the queue.
  void enqueue(int item)
  {
    if (rear == SIZE)   // Queue is full
      return;
    if(front == -1 && rear == -1)
      front = rear = 0;
    else
      rear++;
    array[rear] = item;
  }

  // Method to remove an item from queue.
  int dequeue()
  {
    if (front > rear)
      return -1;
    int item = array[front];
    front++;
    return item;
  }
};

/* enqueue(int) & dequeue() are available on the given queues.*/
class Stack {
 public:
  void push(QueueArray* qa1, QueueArray* qa2, int item) {
    int val = qa1->dequeue();
    while(val != -1) {
      qa2->enqueue(val);
      val = qa1->dequeue();
    }
    qa1->enqueue(item);
    val = qa2->dequeue();
    while(val != -1) {
      qa1->enqueue(val);
      val = qa2->dequeue();
    }
  }
  int pop(QueueArray* qa1, QueueArray* qa2) {
    return qa1->dequeue();
  }
};

int main()
{
  int t, n, q1, q2, k;
  cin>>t;
  Stack st1;
  QueueArray qa1;
  QueueArray qa2;
  while(t>0)
  {
    cin>>q1;
    if(q1 == 1)
    {
      cin>>q2;
      st1.push(&qa1, &qa2, q2);
    }
    else
    {
      cout<<st1.pop(&qa1, &qa2)<<" ";
    }
    t--;
  }
  cout<<endl;
  return 0;
}