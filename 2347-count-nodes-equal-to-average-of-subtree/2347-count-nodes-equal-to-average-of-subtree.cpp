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
int count=0;
    pair<int,int> inOrder(TreeNode* node){
        if (!node) return {0, 0};
        auto [sumL, iL]=inOrder(node->left);
        int sum=node->val, i=1;
        auto [sumR, iR]=inOrder(node->right);
        sum+=(sumL+sumR);
        i+=(iL+iR);
        if (sum/i==node->val) count++;
        return {sum, i};
    }
    int averageOfSubtree(TreeNode* root) {
        inOrder(root);
        return count;
    }
};