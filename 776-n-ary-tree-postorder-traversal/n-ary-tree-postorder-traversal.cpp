/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>res;
    void f(Node* root)
    {
        if(!root)
        return ;
        auto x=root->children;
        for(auto i:x)
        f(i);
        // cout<<root->val;
        res.push_back(root->val);
        return ;
    }
    vector<int> postorder(Node* root) {
        f(root);
        return res;
    }
};