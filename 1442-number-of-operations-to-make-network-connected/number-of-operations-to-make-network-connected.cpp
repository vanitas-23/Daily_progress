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
    int makeConnected(int n, vector<vector<int>>& conn) {
        DisjointSet ds(n);
        int u=0;
        for(auto i:conn)
        {
            if(ds.find(i[0])==ds.find(i[1]))
            u++;
            ds.unite(i[0],i[1]);
        }
        if(u+1<ds.size())
        return -1;
        //cout<<u<<" "<<ds.size();
        return ds.size()-1;
    }
};