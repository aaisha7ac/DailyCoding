//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    
    // TC : O(n)
    // SC : O(n) , n = height of the tree
    
public:


    bool isleaf(Node *root) {
        
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        
        return false;
    }
    
    
    void addleaf(Node *root,vector<int> &ans) {
        
        if(isleaf(root)) {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left) addleaf(root->left,ans);
        if(root->right) addleaf(root->right,ans);
        
    }
    
    
    void add_rightboundary(Node *root,vector<int> &ans) {
        
        Node* curr = root->right;
        vector<int> temp;
        
        while(curr != NULL) {
            if(isleaf(curr) == false) {
                temp.push_back(curr->data);
            }
            
            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        } 
        
        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }
    
    
    void add_leftboundary(Node *root,vector<int> &ans) {
        
        Node* curr = root->left;
        
        while(curr != NULL) {
            if(isleaf(curr) == false) {
                ans.push_back(curr->data);
            }
            
            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        } 
    }
    
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        
        // addleaf function will handle all leaf nodes , if root is leaf it will handle
        
        if(isleaf(root) == false) {
            ans.push_back(root->data);
        }
    
        add_leftboundary(root,ans);
        addleaf(root,ans);
        add_rightboundary(root,ans);
        
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends