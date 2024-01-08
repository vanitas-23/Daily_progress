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
 const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void f(int l,int h,int& sum,TreeNode* root){
        if(!root)
        return ;
        f(l,h,sum,root->left);
        if(root->val >= l && root->val <=h)
        sum+=root->val;
        f(l,h,sum,root->right);
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        int sum=0;
        f(l,h,sum,root);
        return sum;
    }
};