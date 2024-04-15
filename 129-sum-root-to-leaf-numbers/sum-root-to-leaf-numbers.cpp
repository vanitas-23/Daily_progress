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
    void f(TreeNode* root,int& sum,int curr)
    {
        if(!root)
        return ;
        curr=curr*10+root->val;
        if(!root->left && !root->right)
            sum+=curr;
        f(root->left,sum,curr);
        f(root->right,sum,curr);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        f(root,sum,0);
        return sum;
    }
};