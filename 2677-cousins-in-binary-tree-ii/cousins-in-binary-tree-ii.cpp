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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,nullptr});
        while(!q.empty())
        {
            int n=q.size();
            map<TreeNode*,int>mp;
            vector<pair<TreeNode*,TreeNode*>>arr;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                arr.push_back(x);
                q.pop();
                if(x.first->left)
                q.push({x.first->left,x.first});
                if(x.first->right)
                q.push({x.first->right,x.first});
                mp[x.second]+=x.first->val;
                sum+=x.first->val;
            }
            for(auto i:arr)
            i.first->val=sum-mp[i.second];
        }
        return root;
    }
};