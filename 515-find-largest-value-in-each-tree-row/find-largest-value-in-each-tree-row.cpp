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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)
        return {};
        queue<TreeNode*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty()){
            int mx=INT_MIN;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto temp=q.front();
                q.pop();
                mx=max(mx,temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};