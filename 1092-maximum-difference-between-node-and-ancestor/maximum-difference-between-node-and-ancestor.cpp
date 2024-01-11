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
    int maxAncestorDiff(TreeNode* root) {
        using Node=TreeNode;
        unordered_map<Node*,Node*>mp;
        mp[root]=nullptr;
        queue<Node*>q;
        q.push(root);
        int ans=-1;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            auto y=x;
            while(mp[x]!=nullptr)
            {
                ans=max(ans,abs(y->val-mp[x]->val));
                x=mp[x];
            }
            if(y->left)
            {
                mp[y->left]=y;
                q.push(y->left);
            }
            if(y->right)
            {
                mp[y->right]=y;
                q.push(y->right);
            }
        }
        return ans;
    }
};