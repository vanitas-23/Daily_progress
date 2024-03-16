/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #define Node TreeNode
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<Node*,Node*>mp;
        mp[root]=nullptr;
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        unordered_map<Node*,bool>vis;
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(x->left)
            mp[x->left]=x,q.push(x->left);
            if(x->right)
            mp[x->right]=x,q.push(x->right);
        }
        q.push(target);
        vis[target]=1;
        while(!q.empty() && k>=0)
        {
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left && vis[x->left]==0)
                q.push(x->left),vis[x->left]=1;
                if(x->right && vis[x->right]==0)
                q.push(x->right),vis[x->right]=1;;
                if(mp[x] && vis[mp[x]]==0)
                q.push(mp[x]),vis[mp[x]]=1;
            }
            k--;
            ans=temp;
        }
        if(k<0)
        return ans;
        return {};
    }
};