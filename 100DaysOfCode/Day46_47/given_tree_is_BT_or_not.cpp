
#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int data;
   Node *left, *right;
   Node(int val){
     data=val;
     left=NULL;
     right=NULL;
   }
};
class BST{
  Node* root;
  public:
  BST(){
    root=NULL;
  }
  void buildTree(int arr[], int n);
  int isBinarySearchTree();
};

void BST::buildTree(int arr[], int n)
{
  if (n <= 0 || arr[0] == -1) return;
  
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

int checkBinarySearchTree(Node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return checkBinarySearchTree(root->left, min, root->data) && checkBinarySearchTree(root->right, root->data, max);
}
int BST::isBinarySearchTree() {
    return checkBinarySearchTree(root, INT_MIN, INT_MAX);
}


int main()
{
  BST T;
  int t, n, i;
  cin>>t;
  while (t--) {
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
      cin>>a[i];
    T.buildTree(a, n);
    cout<<T.isBinarySearchTree()<<endl;
  }
  return 0;
}

