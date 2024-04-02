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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=nullptr;
        q.push(root);
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            if(x->left)
            mp[x->left]=x,q.push(x->left);
            if(x->right)
            mp[x->right]=x,q.push(x->right);
        }
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        unordered_set<int>ress;
        for(auto i:mp)
        {
            if(st.find(i.first->val)!=st.end())
            {
                //cout<<i.first->val<<" ";
                if(i.first->left)
                mp[i.first->left]=nullptr;
                if(i.first->right)
                mp[i.first->right]=nullptr;
                auto x = mp[i.first];
                if(x==nullptr)
                {
                    ress.insert(i.first->val);
                    continue;
                }
               // cout<<x->val<<" ";
                if(x->left==i.first)
                x->left=nullptr;
                if(x->right==i.first)
                x->right=nullptr;
            }
        }
        vector<TreeNode*>res;
        for(auto i:mp)
        if(ress.find(i.first->val)==ress.end())
        if(i.second==nullptr)
        res.push_back(i.first);
        return res;
    }
};