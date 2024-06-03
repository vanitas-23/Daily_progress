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
    int f(int n, vector<int> a)
{
    pair<int, int> p[n];
	vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        
        // Storing the original position of a[i]
        p[i].second = i;
    }
    
    sort(p, p+n);
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {	
    	//visited[i]=true indicates that index i belongs to a cycle that is already counted
        
        //p[i].second = i denotes that the ith element was at its correct position
        
        if (visited[i] || p[i].second == i)
            continue;
            
        int cycle_size = 0;
        int j = i;
        
        //Counting the size of the cycle
        while (!visited[j])
        {
            visited[j] = 1;
            j = p[j].second;
            cycle_size++;
        }
        
        ans += (cycle_size - 1);
    }
    
    return ans;
    
}
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>arr;
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                arr.push_back(x->val);
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
            }
            ans+=f(n,arr);
        }
        return ans;
    }
};