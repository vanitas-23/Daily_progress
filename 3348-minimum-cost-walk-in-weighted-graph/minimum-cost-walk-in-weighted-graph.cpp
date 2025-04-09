
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
    vector<int> minimumCost(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        vector<int>ans;
        DisjointSet ds(n);
        map<int,int>mp;
        for(int i=0;i<e.size();i++)
        {
            int a=e[i][0],b=e[i][1];
            ds.unite(a,b);
        }
        for(int i=0;i<e.size();i++)
        {
            if(mp.find(ds.find(e[i][0]))==mp.end())
            mp[ds.find(e[i][0])]=e[i][2];
            else
            mp[ds.find(e[i][0])]&=e[i][2];
        }
        for(auto i:q)
        {
            if(ds.isSame(i[0],i[1]))
            ans.push_back(mp[ds.find(i[0])]);
            else
            ans.push_back(-1);
        }
        return ans;
    }
};