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
class FindElements {
public:
    set<int>st;
    void dfs(TreeNode* root,int data,set<int>& st)
    {
        root->val=data;
        st.insert(data);
        if(root->left)
        dfs(root->left,2*data+1,st);
        if(root->right)
        dfs(root->right,2*data+2,st);
    }
    FindElements(TreeNode* root) {
        st.clear();
        dfs(root,0,st);
    }
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */