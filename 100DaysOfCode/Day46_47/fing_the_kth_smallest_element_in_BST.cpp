#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left,*right;
  Node(int val){
  	data=val;
    left=NULL;
    right=NULL;
  }
};
class Tree{
  Node* root;
  public:
  	Tree(){
      root=NULL;
    }
  Node* getRoot(){
    return root;
  }
  void buildTree(int arr[], int n);
};

void Tree::buildTree(int arr[], int n)
{
  if (n <= 0 || arr[0] == -1) root=NULL;
  
  Node* node = new Node(arr[0]);
  queue <Node*> q;
  q.push(node);

  int i = 1;
  while (i < n && !q.empty())
  {
    Node* parent = q.front();
    q.pop();

    // If left child exists
    if (arr[i] != -1)
    {
      parent->left = new Node(arr[i]);
      q.push(parent->left);
    }
    i++;

    // If right child exists
    if (i < n && arr[i] != -1)
    {
      parent->right = new Node(arr[i]);
      q.push(parent->right);
    }
    i++;
  }
  root=node;
}

/* 
 *  class Node
{
public:
  int data;
  Node *left,*right;
  Node(int val){
  	data=val;
    left=NULL;
    right=NULL;
  }
};
class Tree{
  Node* root;
  public:
  	Tree(){
      root=NULL;
    }
  Node* getRoot(){
    return root;
  }
  void buildTree(int arr[], int n);
};*/
int kSmallest(Node* root, int k){
  // Write your code here
  
}

int main()
{
  int n, i;
  cin>>n;
  int a[n];
  Tree t;
  for(i=0;i<n;i++)
    cin>>a[i];
  if(n!=0)
   	t.buildTree(a, n);
  int k;
  cin>>k;
  cout<<kSmallest(t.getRoot(), k);
  return 0;
}