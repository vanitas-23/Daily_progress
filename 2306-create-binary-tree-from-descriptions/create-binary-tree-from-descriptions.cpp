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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<TreeNode*,TreeNode*>par;
        unordered_map<int,TreeNode*>mp;
        for(auto i:des)
        {
            if(mp.find(i[0])==mp.end())
            mp[i[0]]=new TreeNode(i[0]);
            if(mp.find(i[1])==mp.end())
            mp[i[1]]=new TreeNode(i[1]);
            if(i[2])
            mp[i[0]]->left=mp[i[1]];
            else
            mp[i[0]]->right=mp[i[1]];
            par[mp[i[1]]]=mp[i[0]];
        }
        for(auto i:mp)
        {
            if(par.find(i.second)==par.end())
            return i.second;
        }
        return nullptr;
    }
};