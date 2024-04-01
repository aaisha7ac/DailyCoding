/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    // TC : O(m * n) m,n no.of nodes in tree and subtree
    // SC : O(H) , auxiliary stack space

public:

    bool ans = false;

    bool isSameTree(TreeNode* p,TreeNode* q) {

        if(p == NULL || q == NULL) {
            return (p==q);
        }

        if(p->val != q->val) {
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }


    void inordertraversal(TreeNode* root,TreeNode* subRoot) {

        if(root != NULL) {

            inordertraversal(root->left,subRoot);

            // bool temp = isSameTree(root,subRoot);
            // if(temp) {
            //     ans = temp;
            // }

            if(isSameTree(root,subRoot)) ans = true;

            inordertraversal(root->right,subRoot);

        }
    }
    

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        inordertraversal(root,subRoot);
        return ans;

    }
};