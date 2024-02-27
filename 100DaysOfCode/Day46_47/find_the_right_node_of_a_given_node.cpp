#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    void insertLevelOrder(int arr[], int i, int n);
    void buildTree(int arr[], int n);
    int findRightSibling(int key);
 
};
 void BinaryTree::insertLevelOrder(int arr[], int i, int n) {
        if (i < n) {
            Node* temp = new Node(arr[i]);
            root = temp;

            insertLevelOrder(arr, 2 * i + 1, n);
            insertLevelOrder(arr, 2 * i + 2, n);
        }
    }

    void BinaryTree::buildTree(int arr[], int n) {
        if (n <= 0 || arr[0] == -1)
            return;

        root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (i < n && !q.empty()) {
            Node* parent = q.front();
            q.pop();

            // If left child exists
            if (arr[i] != -1) {
                parent->left = new Node(arr[i]);
                q.push(parent->left);
            }
            i++;

            // If right child exists
            if (i < n && arr[i] != -1) {
                parent->right = new Node(arr[i]);
                q.push(parent->right);
            }
            i++;
        }
    }

int BinaryTree::findRightSibling(int key) {
  // Write your code here
  if(root == NULL) {
    return -1;
  }
  queue <Node*> q;
  q.push(root);
  vector<int>temp;
  Node* var = new Node(-1);
  while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    	temp.push_back(-1); // pushing -1 after each label order traversal
    }
    int n = temp.size();
        for(int i = 0; i < n; i++) {
        // cout << temp[i] << " ";
        if(temp[i] == key && i != n - 1) {
            return temp[i+1];
        }
    }
    return -1;
}


int main() {
    int n, i;
    BinaryTree tree;

    cin >> n;
    int* a = new int[n];

    if (n > 0) {
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> i;
        tree.buildTree(a, n);
    }

    cout << tree.findRightSibling(i);

    delete[] a;
    return 0;
}