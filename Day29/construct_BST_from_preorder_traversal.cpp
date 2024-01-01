class Solution {

    // TC : O(n)
    // SC : O(n) , auxiliary space
public:

    TreeNode* constructPreorder(vector<int>& preorder,int &i,int bound) {

        if(i == preorder.size() || preorder[i] > bound) {
            return NULL;
        } 

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = constructPreorder(preorder,i,root->val);
        root->right = constructPreorder(preorder,i,bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return constructPreorder(preorder,i,INT_MAX);
    }
};