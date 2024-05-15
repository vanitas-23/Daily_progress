class Solution {
public:
    
    int solve(vector<int>& a, int ind, int s, int t, vector<vector<int>> &v)
    {
        int n  = a.size();
        if(ind == n)
        {
           if(t == s)
               return 1;
            return 0;
        }
        
        if(v[ind][s] != -1)
            return v[ind][s];
        
        int in = solve(a,ind+1, s|a[ind],t,v);
        int out = solve(a,ind+1, s,t,v);
        
        return v[ind][s] = in+out;
        
        
    }
    
    int countMaxOrSubsets(vector<int>& a) {
        
        int t = 0;
        for(auto h : a)
        {
            t|=h;
        }
        
        int n = a.size();
        
        vector<vector<int>> v(n, vector<int>(1000000,-1));
        
        int ans = solve(a,0,0,t,v);
        
        return ans;
    }
};