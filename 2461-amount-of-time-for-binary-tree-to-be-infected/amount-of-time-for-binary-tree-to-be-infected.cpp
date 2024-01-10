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
   
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mp;
        using Node=TreeNode;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();q.pop();
            if(it->left){
                mp[it->val].push_back(it->left->val);
                mp[it->left->val].push_back(it->val);
                q.push(it->left);
            }
            if(it->right){
                mp[it->val].push_back(it->right->val);
                mp[it->right->val].push_back(it->val);
                q.push(it->right);
            }
        }
        queue<pair<int,int>>pq;
        pq.push({start,0});
       
        int steps=0;
        unordered_map<int,int>xp;
        while(!pq.empty()){
             int x=pq.front().first;
            steps=pq.front().second;
             pq.pop();
             xp[x]=1;
             for(int i:mp[x]){
                 if(xp.find(i)==xp.end())
                 pq.push({i,steps+1});
             }
        }
        return steps;
    }
};