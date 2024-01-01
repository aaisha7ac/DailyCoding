// TC : O(2n)
// SC : O(1)

int findpredecessor (TreeNode *root, int key) {
    int pred = -1;
    while(root != NULL) {
        if(root->data >= key) {
            root = root->left;
        }
        else {
            pred = root->data;
            root = root->right;
        }

    }
    return pred;
}

int findSuccessor (TreeNode *root, int key) {
    int succ = -1;
    while(root != NULL) {
        if(root->data <= key) {
            root = root->right;
        }
        else { // root->data > key
            succ = root->data;
            root = root->left;
        }
    }
    return succ;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pred = findpredecessor(root,key);
    int succ = findSuccessor(root,key);

    return {pred,succ};
}