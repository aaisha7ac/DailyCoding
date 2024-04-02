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

    // TC : O(n)
    // SC : O(n) + O(n) , for map and auxiliary stack space

public:

    TreeNode* build(vector<int>& inorder,int instart,int inend,vector<int>& preorder,int prestart,int preend,map<int,int> &mp) {

        if(instart > inend || prestart > preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int numsLeft = inroot - instart;

        root->left = build(inorder,instart,inroot-1,preorder,prestart+1,prestart+numsLeft,mp);

        root->right = build(inorder,inroot+1,inend,preorder,prestart+numsLeft+1,preend,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int,int>mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
        return root;

        
    }
};