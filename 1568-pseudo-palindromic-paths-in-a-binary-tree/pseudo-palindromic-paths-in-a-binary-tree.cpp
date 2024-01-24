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
    void f(TreeNode* root,int& res,vector<int>x)
    {
        if(!root)
        return ;
        x[root->val]=!x[root->val];
        if(!root->left && !root->right)
        {
            int sm=accumulate(x.begin(),x.end(),0);
            if(sm<2)
            res++;
            return;
        }
        f(root->left,res,x);
        f(root->right,res,x);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res=0;
        vector<int>arr(10);
        f(root,res,arr);

        return res;
    }
};