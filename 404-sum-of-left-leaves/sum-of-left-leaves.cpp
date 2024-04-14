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
    void f(TreeNode* root,int& sum,int isL)
    {
        if(!root)
        return ;
        if(!root->left && !root->right)
        {
            if(isL)
            sum+=root->val;
        }
        f(root->left,sum,1);
        f(root->right,sum,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        f(root,sum,0);
        return sum;
    }
};