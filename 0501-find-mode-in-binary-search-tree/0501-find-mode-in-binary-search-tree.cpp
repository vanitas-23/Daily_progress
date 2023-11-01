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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            mp[it->val]++;
            if(it->left)
            q.push(it->left);
            if(it->right)
            q.push(it->right);
        }
        int mx=0;
        for(auto i:mp)
        mx=max(mx,i.second);
        for(auto i:mp)
        if(i.second==mx)
        res.push_back(i.first);
        return res;
    }
};