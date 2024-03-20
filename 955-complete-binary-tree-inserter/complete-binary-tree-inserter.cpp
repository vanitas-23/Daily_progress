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
class CBTInserter {
public:
    queue<Node*>q;
    Node* x;
    CBTInserter(TreeNode* root) {
        queue<Node*>d;
        d.push(root);
        while(!d.empty())
        {
            auto x=d.front();
            d.pop();
            if(!x->left || !x->right)
            q.push(x);
            if(x->left)
            d.push(x->left);
            if(x->right)
            d.push(x->right);
        }
        
        x=root;
    }
    
    int insert(int val) {
        auto x = q.front();
        if(x->left==nullptr)
        {
            x->left=new Node(val);
            q.push(x->left);
        }
        else{
            x->right=new Node(val);
            q.push(x->right);
        }
        if(x->left && x->right)
        q.pop();
        return x->val;
    }
    
    TreeNode* get_root() {
        return x;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */