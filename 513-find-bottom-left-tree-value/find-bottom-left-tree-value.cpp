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
        int ans=root->val;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                if(i==0)
                ans=x->val;
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
            }
        }
        return ans;
    }
};