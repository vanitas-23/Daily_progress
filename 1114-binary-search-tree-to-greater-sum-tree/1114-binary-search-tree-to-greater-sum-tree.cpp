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
    int data=-1;
    void f(TreeNode* root){
        if(!root)
        return ;
        f(root->right);
        if(data!=-1)
        root->val+=data;
        data=root->val;
        f(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        return root;
    }
};