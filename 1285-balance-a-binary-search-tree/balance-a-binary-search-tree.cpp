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
    void f(TreeNode* root,vector<int>& arr)
    {
        if(!root)
        return ;
        f(root->left,arr);
        arr.push_back(root->val);
        f(root->right,arr);
    }
     TreeNode* balanceBST(int l,int r,vector<int>& arr){
        if (l>r) return nullptr;
        int m=(l+r)/2;
        TreeNode* left=balanceBST(l, m-1,arr);
        TreeNode* right=balanceBST(m+1, r,arr);
        return new TreeNode(arr[m], left, right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        f(root,arr);
        return balanceBST(0,arr.size()-1,arr);

    }
};