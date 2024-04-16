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
    void f(TreeNode* root,int val,int depth)
    {
        if(!root)
        return ;
        //cout<<depth<<" "<<root->val<<endl;
        if(depth==1)
        {
            auto l = root->left;
            auto r = root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=l;
            root->right->right=r;
            return ;
        }
        f(root->left,val,depth-1);
        f(root->right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* ans=new TreeNode(val);
            ans->left=root;
            return ans;
        }
        f(root,val,depth-1);
        return root;
    }
};