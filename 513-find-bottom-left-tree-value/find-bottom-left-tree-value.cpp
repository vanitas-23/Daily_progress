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
 #define Node TreeNode
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<Node*>q;
        q.push(root);
       // int ans=root->val;
       Node* x;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                x=q.front();
                q.pop();
                if(x->right)
                q.push(x->right);
                if(x->left)
                q.push(x->left);
            }
        }
        return x->val;
    }
};