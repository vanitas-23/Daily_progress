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
public:
    bool f(TreeNode* root)
    {
        
        if(root->val==1)
        return 1;
        else if(root->val==0)
        return 0;
        int l = f(root->left);
        int r = f(root->right);
        if(root->val==2)
        return l|r;
        return l&r;
    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};