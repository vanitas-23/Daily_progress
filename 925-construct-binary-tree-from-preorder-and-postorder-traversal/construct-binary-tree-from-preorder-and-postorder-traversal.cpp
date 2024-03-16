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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int,int>lft,rgt;
        for(int i=1;i<pre.size();i++)
        lft[pre[i-1]]=pre[i];
        for(int i=1;i<post.size();i++)
        rgt[post[i]]=post[i-1];
        TreeNode* ans= new TreeNode(pre[0]);
        unordered_map<int,bool>vis;
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                if(lft.find(x->val)!=lft.end() && !vis[lft[x->val]])
                {
                    x->left=new TreeNode(lft[x->val]);
                    q.push(x->left);
                    vis[lft[x->val]]=1;
                }
                if(rgt.find(x->val)!=rgt.end() && !vis[rgt[x->val]])
                {
                    x->right=new TreeNode(rgt[x->val]);
                    q.push(x->right);
                    vis[rgt[x->val]]=1;
                }
            }
        }
        return ans;
    }
};