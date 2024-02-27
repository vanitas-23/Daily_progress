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
    int diameterOfBinaryTree(TreeNode* root) {
        queue<Node*>q;
        q.push(root);
        Node* x;
        unordered_map<Node*,Node*>par;
        par[root]=nullptr;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            if(x->left)
            q.push(x->left),par[x->left]=x;
            if(x->right)
            q.push(x->right),par[x->right]=x;
        }
        q.push(x);
        int ans=0;
        unordered_map<Node*,bool>vis;
        vis[x]=1;
        while(!q.empty())
        {
             ans++;
            int n=q.size();
            for(int i=0;i<n;i++){
            x=q.front();
            q.pop();
           
            if(x->left && !vis[x->left])
            q.push(x->left),vis[x->left]=1;
            if(x->right  && !vis[x->right])
            q.push(x->right),vis[x->right]=1;
            if(par[x] && !vis[par[x]])
            q.push(par[x]),vis[par[x]]=1;
        }
        }
        return ans-1;
    }
};