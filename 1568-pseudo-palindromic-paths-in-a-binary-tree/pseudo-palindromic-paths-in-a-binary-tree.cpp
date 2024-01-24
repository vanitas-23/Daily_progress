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
    void f(TreeNode* root,int& res,int& arr)
    {
        if(!root)
        return ;
        
        arr=arr^(1<<(root->val));
        
        if(!root->left && !root->right)
        {
            if((arr&(arr-1))== 0)
            res++;
        }
        f(root->left,res,arr);
        f(root->right,res,arr);
        arr=arr^(1<<(root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res=0;
        int arr=0;
        f(root,res,arr);

        return res;
    }
};