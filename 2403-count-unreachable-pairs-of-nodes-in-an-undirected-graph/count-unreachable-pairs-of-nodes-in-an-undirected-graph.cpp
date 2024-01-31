#define ll long long
class DisjointSet {
    public:
        DisjointSet(int n) : N(n), sz(n), pars(n, -1) {
        }
        void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }
        int find(int x) { return pars[x] < 0 ? x : pars[x] = find(pars[x]); }
        int size() { return sz; }
        int count(int x) { return -pars[find(x)]; }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) { return false; }
            --sz;
            if (pars[x] < pars[y]) { swap(x, y); }
            pars[y] += pars[x];
            pars[x] = y;
            return true;
        }
        bool isSame(int x, int y) { return find(x) == find(y); }
    private:
        int N, sz;
        vector<int> pars;
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto i:edges)
        ds.unite(i[0],i[1]);

        vector<int>arr[n];
        for(int i=0;i<n;i++)
        arr[ds.find(i)].push_back(i);
        long long ans=0;
        vector<ll>req;
        for(int i=0;i<n;i++)
        if(arr[i].size())
        req.push_back(arr[i].size());
        vector<ll>mn=req;
        for(int i=req.size()-2;i>=0;i--)
            req[i]+=req[i+1];
        
        for(int i=0;i<mn.size();i++)
        if(i+1<mn.size())
        ans+=(mn[i]*req[i+1]);
        return ans;
    }
};