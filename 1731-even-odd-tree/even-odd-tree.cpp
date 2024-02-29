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
    bool isEvenOddTree(TreeNode* root) {
        queue<Node*>q;
        q.push(root);
        int j=0;
        while(!q.empty())
        {
            int n=q.size();
            int curr=-1;
            for(int i=0;i<n;i++)
            {
                
                auto x=q.front();
                q.pop();
                int ele=x->val;
               // int curr=ele;
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
                if(j%2)
                {
                    if(ele%2)
                    return 0;
                    if(i==0)
                    curr=ele;
                    else if(curr<=ele)
                    return 0;
                    curr=ele;
                }
                else
                {
                   // cout<<curr<<" "<<ele<<endl;
                    if(ele%2==0)
                    return 0;
                    if(i==0)
                    curr=ele;
                    else if(curr>=ele)
                    return 0;
                    curr=ele;
                }
            }
            j++;
        }
        return 1;
    }
};