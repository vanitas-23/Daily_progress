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
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n+1);
        vector<int>cost(n+1,1e9);
        for(auto i:roads)
        {
            ds.unite(i[0],i[1]);
            cost[ds.find(i[0])]=min(cost[ds.find(i[0])],i[2]);
            cost[ds.find(i[1])]=min(cost[ds.find(i[1])],i[2]);
           // cout<<i[0]<<" "<<ds.find(i[0])<<endl;
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)
        {
            if(ds.isSame(i,1))
            ans=min(ans,cost[i]);
        }
        return ans;
    }
};