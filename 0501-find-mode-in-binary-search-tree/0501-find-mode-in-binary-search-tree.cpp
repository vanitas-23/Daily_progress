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

private:
    int last = INT_MIN;
    int count = 0;
    int max = 0;
    std::vector<int> modes;

    void traverse(TreeNode* node) {

        if (!node) return;

        traverse(node->left);

        if (last == node->val) 
            count++;
         else 
            count = 1;
        

        if (count > max) {
            max = count;
            modes.clear();
            modes.push_back(node->val);}
          else if (count == max) 
            modes.push_back(node->val);

        last = node->val;

        traverse(node->right);

    
        }

public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return modes;
    }
};